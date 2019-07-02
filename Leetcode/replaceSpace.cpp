class Solution {
public:
	void replaceSpace(char *str,int length) {
            //判断能否进行插入
            int olderNumber=0;
            int replaceNumber=0;
            while(str[olderNumber]!='\0'){
                //计算空格的个数
                if(str[olderNumber]==' '){
                    replaceNumber++;
                }
                //计算字符串的老长度
                olderNumber++;
            }
            
            /*
            ** 不要这么算 olderNumber加完之后才进行的判断 明显错误
            while(str[olderNumber]!='\0'){
                olderNumber++;
                if(str[olderNumber]==' '){
                    replaceNumber++;
                }
            }
            */
           
            int newNumber=replaceNumber*2+olderNumber;
	        if(length<newNumber){
                   return;
            }
            //进行替换
            while(olderNumber>=0&&newNumber>olderNumber){
                if(str[olderNumber]==' '){
                    str[newNumber--]='0';
                    str[newNumber--]='2';
                    str[newNumber--]='%';
                }
                else{
                    str[newNumber--]=str[olderNumber];
                }
                olderNumber--;
            }
    }
};