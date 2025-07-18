#include <iostream>
#include <cassert>


class Solution {
public:
    std::string intToRoman(int num) {
        std::string ans="";
		int ost;

		ost = num%10;
		if(ost==9){
			ans="IX";
		}
		else if((ost>4)&&(ost<9)){
			ans="V"+std::string(ost-5, 'I');
		}
		else if(ost==4){
			ans="IV";
			
		}
		else if(ost>0){
			ans=std::string(ost, 'I');
		}

		num/=10;
		if(num==0){
			return ans;
		}

		ost = num%10;
		if(ost==9){
			ans="XC"+ans;
		}
		else if((ost>4)&&(ost<9)){
			ans="L"+std::string(ost-5, 'X')+ans;
		}
		else if(ost==4){
			ans="XL"+ans;
			
		}
		else if(ost>0){
			ans=std::string(ost, 'X')+ans;
		}

		num/=10;
		if(num==0){
			return ans;
		}

		ost = num%10;
		if(ost==9){
			ans="CM"+ans;
		}
		else if((ost>4)&&(ost<9)){
			ans="D"+std::string(ost-5, 'C')+ans;
		}
		else if(ost==4){
			ans="CD"+ans;
			
		}
		else if(ost>0){
			ans=std::string(ost, 'C')+ans;
		}

		num/=10;
		if(num==0){
			return ans;
		}

		ans = std::string(num, 'M') + ans;

		return ans;
    }
};

int main(){
	Solution test;
	std::cout << test.intToRoman(3749) << std::endl; //"MMMDCCXLIX"
	std::cout << test.intToRoman(58) << std::endl; //LVIII
	std::cout << test.intToRoman(1994) << std::endl; //MCMXCIV
	return 0;
}