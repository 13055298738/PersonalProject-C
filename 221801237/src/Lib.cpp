#include"Lib.h"


/*�ֵ�������*/
bool wordCount::cmp_raw_word(const string &a,const string &b){
	return a<b;
}


/*���ʳ��ִ�������������*/
bool wordCount::cmp_word_statistics(const word &a,const word &b){
	return a.cnt>b.cnt;
}


/*���ȡ�Դ�����Դ�ļ�����Сд��ĸ������к��ּ��ַ�*/
bool wordCount::skip(){
    scanf("%*[^a-z||A-Z]"); return true;
}


void wordCount::readfile(){
	freopen("in.txt","r",stdin);
	while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF){
        number_of_words++;
        /*��ֻ������ĸ��д�ĵ��ʵ�����ĸת����Сд*/
        if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])) _word[0]|=1<<5;
        raw_word.push_back(_word);
    }
}


void wordCount:outPut(){
	/*�ض���������� out.txt �ļ���������˵����Ϣ*/
   freopen("out.txt","w",stdout);
   printf("-----------------------------------------------\n");
   printf("words:%d\n",number_of_words);
   printf("no.   word              time          frequency\n");
   printf("-----------------------------------------------\n");
}

