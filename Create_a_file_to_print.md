
# Create A File to Print

    int main(int argc, char *argv[]){

        int fd;
        char *name = "helloworld";
        fd = open(name, O_WRONLY | O_CREAT, 0644);
        if (fd == -1) {
            perror("open failed");
            exit(1);
        }

        if (dup2(fd, 1) == -1) {
            perror("dup2 failed"); 
            exit(1);
        }

        // file descriptor 1, i.e. stdout, now points to the file
        // "helloworld" which is open for writing
        // You can now use printf which writes specifically to stdout

        char *hi = "Hello World";
        printf("%s\n", hi);

        exit(0);

    }
