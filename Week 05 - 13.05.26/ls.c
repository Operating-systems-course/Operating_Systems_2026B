#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

void print_permissions(mode_t mode) {

    if (S_ISDIR(mode))
        printf("d");
    else if (S_ISLNK(mode))
        printf("l");
    else
        printf("-");

    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    dir = opendir(".");

    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        if (lstat(entry->d_name, &fileStat) == -1) {
            perror("lstat failed");
            continue;
        }

        print_permissions(fileStat.st_mode);

        printf(" %ld", fileStat.st_nlink);

        struct passwd *pw = getpwuid(fileStat.st_uid);
        if (pw != NULL)
            printf(" %s", pw->pw_name);
        else
            printf(" %d", fileStat.st_uid);

        struct group *gr = getgrgid(fileStat.st_gid);
        if (gr != NULL)
            printf(" %s", gr->gr_name);
        else
            printf(" %d", fileStat.st_gid);

        printf(" %5ld", fileStat.st_size);

        char timeBuffer[80];
        struct tm *timeInfo = localtime(&fileStat.st_mtime);
        strftime(timeBuffer, sizeof(timeBuffer), "%b %d %H:%M", timeInfo);
        printf(" %s", timeBuffer);

        printf(" %s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}