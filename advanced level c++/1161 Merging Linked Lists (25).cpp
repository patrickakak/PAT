#include <iostream>
#include <map>
#include <cmath>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int addr, data, next, flag, order;
};
int num1=0, num2=0;//1长，2短
vector<node> v(100000);
vector<node> ans;
bool cmp(node &a, node &b) {
	if (a.flag!=b.flag) return a.flag>b.flag;
	else return a.order<b.order;
}
bool cmp2(node &a, node &b) {
	return a.order>b.order;
}
int main() {
	//【题意】：将短链表逆序，并入长链表，题目保证较长的链表至
	//少是较短链表的两倍长
	//【分析】：
	int fir1, fir2, n;
	cin >> fir1 >> fir2 >> n;
	for (int i=0; i<n; i++) {
		int addr, data, next;
		scanf("%d%d%d", &addr, &data, &next);
		v[addr].addr=addr, v[addr].data=data, v[addr].next=next;
	}
	int p=fir1;
	while (p!=-1) {
		v[p].flag=1;
		v[p].order=num1++;
		p=v[p].next;
	}
	p=fir2;
	while (p!=-1) {
		v[p].flag=2;
		v[p].order=num2++;
		p=v[p].next;
	}
	if (num1<num2) {
		swap(num1, num2);
		swap(fir1, fir2);
	}
	p=fir1;
	while (p!=-1) {
		v[p].flag=1;
		p=v[p].next;
	}
	p=fir2;
	while (p!=-1) {
		v[p].flag=2;
		p=v[p].next;
	} //第一条长，标记flag=1，第二条短,flag=2，短在前
	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.begin()+num2, cmp2);//短的逆序
	//短的在前num2，长的在后num1
	int cnt1=num2, cnt2=0;
	while (cnt1 <num1+num2 || cnt2<num2) {
		if (cnt1<num1+num2) {
			for (int j=cnt1; j<cnt1+2&&cnt1<num1+num2; j++) {
				ans.push_back(node{v[j].addr, v[j].data});
			}
			cnt1+=2;
		}
		if (cnt2<num2) {
			ans.push_back(node{v[cnt2].addr, v[cnt2].data});
			cnt2+=1;
		}
	}
	for (int i=0; i<num1+num2; i++) {
		if (i!=num1+num2-1) {
			printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+1].addr);
		} else {
			printf("%05d %d -1", ans[i].addr, ans[i].data);
		}
	}
	return 0;
}
