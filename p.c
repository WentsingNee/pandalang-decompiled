#include <stdio.h>
typedef unsigned char undefined;

typedef unsigned char byte;
typedef unsigned int dword;
typedef unsigned long long qword;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef unsigned short word;
typedef int bool;

char outData[1024] = {0};
int index2 = 0;
int index3 = 0;
const true = 1;
const false = 0;
FILE *outFile;

// 貌似用于清空outData变量
// 为什么还要另外写个函数(不能直接memset?)
// 为什么是 0x401

void clearOutData(void)

{
  int index10;

  for (index10 = 1; index10 < 0x401; index10 = index10 + 1) {
    outData[index10] = 0x20;
  }
  return;
}

void lexerMain(char *line)

{
  int lineLength;
  size_t lineLengthTemp;
  int index9;
  int index8;
  int index7;
  int index6;
  int index20;
  int index12;
  int index19;
  int index18;
  int index16;
  int index17;
  int index15;
  int index14;
  int index13;
  int index5;
  int index1;
  bool isAssign;

  int isDecimal = 0;
  clearOutData();
  lineLengthTemp = strlen(line);
  lineLength = (int)lineLengthTemp;
  // out关键字 这玩意还没有实现function呢
  if (((*line == 'o') && (line[1] == 'u')) && (line[2] == 't')) {
    index2 = 7;
    outData[0] = 0x70;
    int index1 = 4;
    // 从引号开始，将这一行所有的内容搬到字符串里面，最后加个分号
    // 如果括号后是"
    // (即 out(string)
    if (line[4] == '\"') {
      for (; index1 < lineLength; index1 = index1 + 1) {
        outData[index2] = line[index1];
        index2 = index2 + 1;
      }
      // 0x3b = ';'   分号
      outData[index2] = 0x3b;
      fprintf(outFile, &outData);
    } else {
      // 数字处理
      if ((((((line[4] == '0') || (line[4] == '1')) || (line[4] == '2')) ||
            (((line[4] == '3' || (line[4] == '4')) ||
              ((line[4] == '5' || ((line[4] == '6' || (line[4] == '7')))))))) ||
           (line[4] == '8')) ||
          (line[4] == '9')) {
        isDecimal = 0;
        for (int index3 = 4; index3 <= lineLength; index3 = index3 + 1) {
          if (line[index3] == '.') {
            isDecimal = 1;
            break;
          }
        }
        if (isDecimal == 1) {
          index2 = 0xc;
          for (; index1 < lineLength; index1 = index1 + 1) {
            outData[index2] = line[index1];
            index2 = index2 + 1;
          }
          outData[index2] = 0x3b;
          fputs(&outData, outFile);
        } else {
          index2 = 0xc;
          for (; index1 < lineLength; index1 = index1 + 1) {
            outData[index2] = line[index1];
            index2 = index2 + 1;
          }
          // 分号
          outData[index2] = 0x3b;
          fputs(&outData, outFile);
        }
      }
    }
  } else {
    // sout函数
    if (((*line == 's') && (line[1] == 'o')) &&
        ((line[2] == 'u' && (line[3] == 't')))) {
      outData[0] = 0x70;
      index2 = 0xc;
      for (index5 = 5; index5 < lineLength; index5 = index5 + 1) {
        outData[index2] = line[index5];
        index2 = index2 + 1;
      }
      outData[index2] = 0x3b;
      fputs(&outData, outFile);
    } else {
      // 同理 fout函数
      if (((*line == 'f') && (line[1] == 'o')) &&
          ((line[2] == 'u' && (line[3] == 't')))) {
        outData[0] = 0x70;
        index2 = 0xc;
        for (index13 = 5; index13 < lineLength; index13 = index13 + 1) {
          outData[index2] = line[index13];
          index2 = index2 + 1;
        }
        outData[index2] = 0x3b;
        fputs(&outData, outFile);
      } else {
        // iout 函数
        // 不是我寻思着你这几个函数的拼装代码都大致一样啊
        if ((((*line == 'i') && (line[1] == 'o')) && (line[2] == 'u')) &&
            (line[3] == 't')) {
          outData[0] = 0x70;
          index2 = 0xc;
          for (index14 = 5; index14 < lineLength; index14 = index14 + 1) {
            outData[index2] = line[index14];
            index2 = index2 + 1;
          }
          outData[index2] = 0x3b;
          fputs(&outData, outFile);
        } else {
          // var关键字
          if (((*line == 'v') && (line[1] == 'a')) && (line[2] == 'r')) {
            isAssign = false;
            for (index15 = 0; index15 <= lineLength; index15 = index15 + 1) {
              if (line[index15] == '\"') {
                isAssign = true;
              }
            }
            if (isAssign) {
              outData[0] = 99;
              index17 = 4;
              index2 = 5;
              for (index16 = 0; index16 <= lineLength; index16 = index16 + 1) {
                outData[index2] = line[index17];
                index17 = index17 + 1;
                index2 = index2 + 1;
              }
              fputs(&outData, outFile);
              fputs(";", outFile);
            } else {
              for (index3 = 4; index3 <= lineLength; index3 = index3 + 1) {
                if (line[index3] == '.') {
                  isDecimal = 1;
                  break;
                }
              }
              if (isDecimal == 1) {
                outData[0] = 0x66;
                index18 = 4;
                index2 = 6;
                for (index19 = 0; index19 <= lineLength;
                     index19 = index19 + 1) {
                  outData[index2] = line[index18];
                  index18 = index18 + 1;
                  index2 = index2 + 1;
                }
                fputs(&outData, outFile);
                fputs(";", outFile);
              } else {
                if (((((((line[6] == '0') || (line[6] == '1')) ||
                        (line[6] == '2')) ||
                       ((line[6] == '3' || (line[6] == '4')))) ||
                      (line[6] == '5')) ||
                     ((line[6] == '6' || (line[6] == '7')))) ||
                    ((line[6] == '8' || (line[6] == '9')))) {
                  *line = 'i';
                  line[1] = 'n';
                  line[2] = 't';
                  fputs(line, outFile);
                  fputs(";", outFile);
                } else {
                  outData[0] = 0x66;
                  index12 = 4;
                  index2 = 6;
                  for (index20 = 0; index20 <= lineLength;
                       index20 = index20 + 1) {
                    outData[index2] = line[index12];
                    index12 = index12 + 1;
                    index2 = index2 + 1;
                  }
                  fputs(&outData, outFile);
                  fputs(";", outFile);
                }
              }
            }
          } else {
            // 不是注释
            if (*line != '#') {
              // if, else, while
              if (((*line == 'i') && (line[1] == 'f')) ||
                  (((*line == 'e' && (((line[1] == 'l' && (line[2] == 's')) &&
                                       (line[3] == 'e')))) ||
                    (((*line == 'w' && (line[1] == 'h')) &&
                      ((line[2] == 'i' &&
                        ((line[3] == 'l' && (line[4] == 'e')))))))))) {
                fputs(line, outFile);
              } else {
                if (*line == '[') {
                  fputs("{", outFile);
                } else {
                  if (*line == ']') {
                    fputs("}", outFile);
                  } else {
                    // iin函数
                    if (((*line == 'i') && (line[1] == 'i')) &&
                        (line[2] == 'n')) {
                      outData[0] = 0x73;
                      index2 = 0xc;
                      for (index6 = 4; index6 < lineLength;
                           index6 = index6 + 1) {
                        outData[index2] = line[index6];
                        index2 = index2 + 1;
                      }
                      outData[index2] = 0x3b;
                      fputs(&outData, outFile);
                      fputs("getchar();", outFile);
                    } else {
                      // sin函数
                      if (((*line == 's') && (line[1] == 'i')) &&
                          (line[2] == 'n')) {
                        outData[0] = 0x73;
                        index2 = 0xc;
                        for (index7 = 4; index7 < lineLength;
                             index7 = index7 + 1) {
                          outData[index2] = line[index7];
                          index2 = index2 + 1;
                        }
                        outData[index2] = 0x3b;
                        fputs(&outData, outFile);
                        fputs("getchar();", outFile);
                      } else {
                        // fin函数
                        if (((*line == 'f') && (line[1] == 'i')) &&
                            (line[2] == 'n')) {
                          outData[0] = 0x73;
                          index2 = 0xc;
                          for (index8 = 4; index8 < lineLength;
                               index8 = index8 + 1) {
                            outData[index2] = line[index8];
                            index2 = index2 + 1;
                          }
                          outData[index2] = 0x3b;
                          fputs(&outData, outFile);
                          fputs("getchar();", outFile);
                        } else {
                          isAssign = false;
                          for (index9 = 0; index9 <= lineLength;
                               index9 = index9 + 1) {
                            if (line[index9] == '=') {
                              isAssign = true;
                            }
                          }
                          if (isAssign) {
                            fputs(line, outFile);
                            // 分号
                            fputs(";", outFile);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}

int main() {
  int isFOF;
  char line[1024];
  FILE *file;
  char fileName[80];

  printf("Panda 编程语言 [版本1.0] \n");
  printf("(c) 2021 \x73\x8b\x51\xa0\x53\x5a "
         "\x4f\xdd\x75\x59\x62\x40\x67\x09\x67\x43\x52\x29");
  while (true) {
    printf("请输入文件:");
    scanf("%s", fileName);
    file = fopen(fileName, "r");
    if (file == (FILE *)0x0)
      break;
    outFile = fopen("code.c", "w");
    fprintf(outFile, "int main(){\n");
    while (true) {
      isFOF = feof(file);
      if (isFOF != 0)
        break;
      fgets(line, 1024, file);
      lexerMain(line);
    }
    fprintf(outFile, "getchar();\n}");
    fclose(outFile);
    system("cc code.c");
    remove("code.c");
    system("start code");
  }
  return 0;
}
