#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


using namespace std;
#define MAX_LENGTH 4<<10//单词的最大长度


typedef struct{
    string str;
    int wordcnt;
    int charcnt;
    int linecnt;
}word;


int number_of_words=0;//记录单词统计总数
vector<string> raw_word;//资源文本中的单词集
vector<word> word_statistics;//统计结果集


/*字典排序比较函数*/
bool cmp_raw_word(const string &a,const string &b){return a<b;}


/*词汇出现次数降序排序比较函数*/
bool cmp_word_statistics(const word &a,const word &b){return a.wordcnt>b.wordcnt;}


/*虚读取以处理资源文件除大小写字母外的所有汉字及字符*/
bool skip(){ scanf("%*[^a-z||A-Z]"); return true;}


bool is_digit(char ch){
	return (ch>='0'&&ch<='9');
}

bool is_alpha(char ch){
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}


bool is_word(const char* str) {

	int char_num_count = 0;	// 开头连续字母的个数

	if (is_digit(*str))		// 如果第一个是数字字符，不是单词 
		return false;

	// 遍历字符串 
	for (const char* p = str; *p != '\0'; p++) {

		if (is_alpha(*p))			// 如果是字符，字母数+1 
			char_num_count++;
		else if (char_num_count < 4)	// 碰到第一个非字母字符时，如果不满4个，不是单词 
			return false;

		if (char_num_count >= 4)
			return true;
	}
	return false;
}

int main(){

	
	/*定义缓存空间*/
	word w;
	char _word[MAX_LENGTH];
	
	
	vector<string>::iterator it,last;
	vector<word>::iterator wit;
	
	
	/*重定向输入流至 input.txt 文件,并读取 input.txt 文件中所有英文单词*/
	freopen("input.txt","r",stdin);
	while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF){
		/*将单词计入*/
		if(is_word(_word)){
            number_of_words++;
	    /*将只有首字母大写的单词的首字母转换成小写*/
	        if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])){
			    _word[0]|=1<<5;
			}
	        raw_word.push_back(_word);
	  
        }
    }
	fstream fin;
	fin.open("input.txt");
    char ch;
    int charcnt=0;
    int linecnt=0;
    while(fin && fin.get(ch)){

        if(is_alpha(ch)||is_digit(ch)){
        	cout << ch;
        	charcnt++;
        	if(ch=='\n'){
   	 	       linecnt++;
	        }
	    }
   	    
    }
    fin.close();
   
   /*重定向输出流至 output.txt 文件并输出相关说明信息*/
    freopen("output.txt","w",stdout);
    printf("characters: %d\n",charcnt);
    printf("words: %d\n",number_of_words);
    printf("lines: %d\n",linecnt+1);
    


   /*若没有检测到输入时,结束程序并返回提示信息*/
    if(!raw_word.size()){
       printf("There is no word in the \"in.txt\" or \"in.txt\" inexistence!\n");
       return 0;
    }


   /*对单词集进行字典排序以便进行出现次数统计操作*/
    sort(raw_word.begin(),raw_word.end(),cmp_raw_word);
    for(last=raw_word.begin(),it=raw_word.begin()+1;it!=raw_word.end();it++){
       if(*it!=*last){
          w.str=*last;
          w.wordcnt=it-last;
		  word_statistics.push_back(w);
          last=it;
		  
        }
    }


   /*弥补跳出循环时最后一个未被计入单词*/
    w.str=*last;
    w.wordcnt=it-last;
    word_statistics.push_back(w);


   /*对结果集进行出现次数关键词降序排序*/
    sort(word_statistics.begin(),word_statistics.end(),cmp_word_statistics);
    bool b=false;
    for(wit=word_statistics.begin();wit!=word_statistics.end();wit++){
      /*为保证统计有意义,对统计数据输出进行调节*/
       if((*wit).wordcnt*1.0/number_of_words>=0.05||((*wit).wordcnt>=2&&(*wit).wordcnt*100.0/number_of_words>=0.01)){
      	  if(wit-word_statistics.begin()<10){
		  
            printf("%s: %d\n",((*wit).str).c_str(),(*wit).wordcnt);
            b=true;
            }

        }


    }


    return 0;
 
} 

	 
