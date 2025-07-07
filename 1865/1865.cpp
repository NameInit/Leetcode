#include <iostream>
#include <vector>
#include <unordered_map>


class FindSumPairs {
private:
	std::vector<int> v1;
	std::vector<int> v2;
	std::unordered_map<int, int> m1;
	std::unordered_map<int, int> m2;

	void __ShowMapNumCount(){
		std::cout << "MAP1: ";
		for(auto [num, count] : m1)
			std::cout << '(' << num << ", " << count << ") ";
		std::cout << std::endl << "MAP2: ";
		for(auto [num, count] : m2)
			std::cout << '(' << num << ", " << count << ") ";
		std::cout << std::endl;
	}

	void __ShowVectorInt(){
		std::cout << "VECTOR1: [";
		for(auto item : v1)
			std::cout << ' ' << item;
		std::cout << " ]" << std::endl << "VECTOR2: [";
		for(auto item : v2)
			std::cout << ' ' << item;
		std::cout << " ]" << std::endl;
	}
public:
	FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) {
		v1=nums1;
		v2=nums2;
		for(auto item : v1){
			m1[item]+=1;
		}
		for(auto item : v2){
			m2[item]+=1;
		}

		// __ShowMapNumCount();
		// __ShowVectorInt();
	}
	
	void add(int index, int val) {
		m2[v2[index]]-=1;
		m2[v2[index]+val]+=1;
		v2[index]+=val;

		// __ShowMapNumCount();
		// __ShowVectorInt();
	}
	
	int count(int tot) {
		int ans=0;

		for(auto [num, count] : m1){
			if(m2.find(tot-num)!=m2.end()){
				ans += count*m2[tot-num];
			}
		}

		return ans;
	}
};

int main(){
	std::vector<int> v1={1, 1, 2, 2, 2, 3};
	std::vector<int> v2={1, 4, 5, 2, 5, 4};
	FindSumPairs test(v1,v2);
	std::cout << test.count(7) << std::endl; //8
	test.add(3, 2);
	std::cout << test.count(8) << std::endl; //2
	std::cout << test.count(4) << std::endl; //1
	test.add(0, 1);
	test.add(1, 1);
	std::cout << test.count(7) << std::endl; //11
	return 0;
}