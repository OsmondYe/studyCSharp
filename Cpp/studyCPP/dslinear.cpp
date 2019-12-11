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

template<typename Elem>
void insert_linked_list(linked_list<Elem>& l,Elem i) {
	
	node<Elem>* p = l.list;
	node<Elem>* n = new node<Elem>(i);
	
	if (!p) {
		//p = n; // Easy Error, p changed, but l.list is not changed
		l.list = n;
	}
	else {
		while (p ->next!= NULL) {
			p = p->next;
		}
		//p = n;	// easy error, set p->next , not p
		p->next =n ;
	}
	
}

template<typename Elem>
bool delete_linked_list(linked_list<Elem>& l, Elem i) {
	bool rt = false; // true, ok, false i not found in l
	if (l.list == NULL) {
		return rt;
	}
	node<Elem>* pre = NULL;
	node<Elem>* cur = l.list; 

	if (cur->e == i) {
		l.list = cur->next;
		delete cur;
		rt = true;
		return rt;
	}
	// init-state, pre(NULL), cur(begin)
	for (; cur != NULL; pre = cur, cur = cur->next) {
		if (cur->e != i) {
			continue;
		}
		else {
			pre->next = cur->next;		// alarm, pre maybe NULL		
			delete cur;
			rt = true;
			break;
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
	linked_list<int> l = create_linked_list(buf);
	node_traverse(l);
	node_reverse(l);  node_traverse(l);
	node_reverse2(l);  node_traverse(l);
	
	clear_linked_list(l);
	//delete_linked_list(head);

	int i = 0;
	while (i < 10) {
		insert_linked_list(l, i++);
	}
	node_traverse(l);

	// delete specific item in list
	i = 0;
	while (i++<100)
	{		
		auto x = rand() % 10;
		cout << "del:" << x << " " <<std::boolalpha<< delete_linked_list(l, x) << endl;
	}

	//}
}

template<typename T>
void reverse_print(node<T>* head) {
	if (head == NULL) {
		return;
	}
	reverse_print(head->next);
	cout << head->e << " ";
}


TEST(DSLinear, LinkedList_ReversePrint) {
	linked_list<int> l = create_linked_list(aux::getSorted(30));
	node_traverse(l);
	reverse_print(l.list); 


	clear_linked_list(l);  cout << endl;
	l = create_linked_list(aux::getRandom(30));
	node_traverse(l);
	reverse_print(l.list);
	cout << endl;
}






