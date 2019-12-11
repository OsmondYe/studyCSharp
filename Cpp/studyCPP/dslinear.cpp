#include "pch.h"
#include "helper.hpp"

//
//	Linked list
//
template <typename elem>
struct node {	
	elem e;
	node<elem>* next;



	node() { next = NULL; }
	node(elem e) { this->e = e; next = NULL; }
};

// �о�������ͨ������, �����ͷ�Ǹ�node�Ļ�,next=NULL, ��������Ϊ�ջ���ֻ��һ��Ԫ��
// Ϊ�˽��������, ������Ʊ�ͷ
template <typename elem>
struct linked_list {
	linked_list() {
		list = NULL;
	}
	node<elem>* list;
};
//typedef �޷���template һ��ʹ��

//ͷ�巨����, 
template <typename elem>
linked_list<elem> create_linked_list(const std::vector<elem>& buf) {
	if (buf.empty()) {
		return linked_list<elem>();
	}

	linked_list<elem> rt;
	node<elem>* previous = NULL;
	for (auto i : buf) {
		node<elem>* x = new node<elem>(i);
		if (previous) {
			previous->next = x;
			previous = previous->next;
		}
		else {
			previous=x;
			rt.list = x;
		}
	}
	return rt;
}

template <typename elem>
void clear_linked_list(linked_list<elem>& l) {
	auto t = l.list;
	l.list = NULL;
	while (t) {
		auto x = t->next;
		delete t;
		t = x;
	}
}

template <typename elem>
void node_traverse(const linked_list<elem>& l) {
	auto x = l.list;
	while (x) {
		cout << x->e << " ";
		x = x->next;
	}
	cout << endl;
}


/* ������ת��
	�㷨ȡ�м�������з���:
		- cur��Чʱ,�����õ�nxt   nxt=cur->next;  
			ֻ������,��cur->next�仯Ϊpreʱ,�������԰�cur����
			cur=nxt ��Ȼ��nxt=cur->next�ɶԳ���
		- ����ת��ʱ,��Ҫpre(previous)	cur->next=pre
			ת�ý��� preҲҪ�䶯, pre=cur
*/
template <typename elem>
void node_reverse(linked_list<elem>& l) {	
	node<elem>* cur = l.list;	
	node<elem>* pre = NULL;
	node<elem>* nxt = NULL;
	if (!cur) {
		return;
	}
	while (cur){
		nxt = cur->next;
		//
		cur->next = pre;
		pre = cur;
		///
		cur = nxt;
	}
	l.list = pre;
}
/*
	while(cur) {
		 ת��;
		 ����;
	}
	�����������,nxtֻ��һ��tmp
	����ǰ��Ҫ�� pre=cur,  ��pre��cur����������к���

	�ٻ�һ�ּ򵥵�˼·:
		һ�β����ĵ�λ��Ϊ	
			һ������ wnd(pre,cur)
			wnd�ṩ����һ����λ�Ĳ���
			wnd�ṩreverse����

*/
template <typename elem>
void node_reverse2(linked_list<elem>& l) {
	node<elem>* cur = l.list;
	node<elem>* pre = NULL;
	if (!cur) {
		return;
	}
	while (cur) {
		node<elem>* nxt = cur->next;
		//  -����ת��
		cur->next = pre;
		/// -���ں��� , cur����ǰ��Ҫ��pre��ȷ������
		pre = cur;
		cur = nxt;
	}
	l.list = pre;
}

TEST(DSLinear, LinkedList_Baisc) {
	vector<int> buf = { 1,2,3,4,5 };
	//vector<int> buf = { 1,2 };
	//for (size_t i = 0; i < 10000000; i++){
	linked_list<int> head = create_linked_list(buf);
	node_traverse(head);
	node_reverse(head);  node_traverse(head);
	node_reverse2(head);  node_traverse(head);
	
	clear_linked_list(head);
	//delete_linked_list(head);
	//}
}








