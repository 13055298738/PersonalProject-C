#include"Lib.h"


/*字典排序函数*/
bool wordCount::cmp_raw_word(const string &a,const string &b){
	return a<b;
}


/*单词出现次数降序排序函数*/
bool wordCount::cmp_word_statistics(const word &a,const word &b){
	return a.wordcnt>b.wordcnt;
}


/*虚读取以处理资源文件除大小写字母外的所有汉字及字符*/
bool wordCount::skip(){
    scanf("%*[^a-z||A-Z]"); return true;
}


void wordCount::wordCount(){
	freopen("in.txt","r",stdin);
	while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF){
        number_of_words++;
        /*将只有首字母大写的单词的首字母转换成小写*/
        if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])) _word[0]|=1<<5;
        raw_word.push_back(_word);
    }
    if(!raw_word.size()){
        printf("There is no word in the \"in.txt\" or \"in.txt\" inexistence!\n");
        printf("-----------------------------------------------\n");
        return 0;
   }
}


void wordCount::characterAndLineCount(char *ch,int *charcnt,int *linecnt){
   fstream fin;
   fin.open("in.txt");
   if(!fin){
		cerr<<"can not open file"<<endl;
		return -1;
   }
   while(fin && fin.get(ch)){
       cout << ch;
       charcnt++;
       if(ch=='\n'){
   	       linecnt++;
       }
   }
   fin.close();
}


void wordCount::outPut(int *number_of_words,int *charcnt,int *linecnt){
	/*重定向输出流至 out.txt 文件并输出相关说明信息*/
   freopen("out.txt","w",stdout);
   printf("-----------------------------------------------\n");
   printf("words:%d\n",number_of_words);
   printf("character:%d\n",charcnt);
   printf("line:%d\n",linecnt);
   printf("no.   word              time          frequency\n");
   printf("-----------------------------------------------\n");
}

