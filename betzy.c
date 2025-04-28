#define openfile(filename, buffer) do { \
    FILE* file = fopen(filename, "rb"); \
    if (!file) { \
        perror("Error opening file"); \
        buffer = NULL; \
        break; \
    } \
    fseek(file, 0, SEEK_END); \
    long fileSize = ftell(file); \
    fseek(file, 0, SEEK_SET); \
    buffer = (char*)malloc(fileSize + 1); \
    if (!buffer) { \
        perror("Memory allocation failed"); \
        fclose(file); \
        break; \
    } \
    if (fread(buffer, 1, fileSize, file) != fileSize) { \
        perror("Error reading file"); \
        free(buffer); \
        fclose(file); \
        buffer = NULL; \
        break; \
    } \
    buffer[fileSize] = '\0';  /* Null-terminate the buffer */ \
    fclose(file); \
} while (0)

#define foreach(__ptr, __len, __item_tn, __body)        \
        for (int __iter = 0; __iter < __len; __iter++)  \
            {                                           \
                __item_tn = __ptr[__iter];              \
                do                                      \
                    __body                              \
                while(0);                               \
            }
