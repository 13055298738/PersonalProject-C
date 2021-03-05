#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


using namespace std;
#define MAX_LENGTH 1<<10//单词的最大长度


typedef struct{
    string str;
    int wordcnt;
    int charcnt;
    int linecnt;
}word;
