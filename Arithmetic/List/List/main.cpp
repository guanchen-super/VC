#include <iostream>

typedef struct _ListNode
{
	int nVal = 0;
	struct _ListNode * pNext = nullptr;
}ListNode;

ListNode * Reverse(ListNode * pHead)
{
	if (nullptr == pHead || nullptr == pHead->pNext)
		return pHead;

	ListNode * pNode = pHead;
	ListNode * pPrev = nullptr;
	ListNode * pNext = nullptr;

	do 
	{
		pNext = pNode->pNext;
		pNode->pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	while (nullptr != pNode->pNext);

	pNode->pNext = pPrev;
	return pNode;
}

int main(int argc, char * argv[])
{
	ListNode * pHead = new ListNode;
	ListNode * pNode = pHead;
	for (int i = 0; i != 10; ++i)
	{
		pNode->nVal = i;
		pNode->pNext = new ListNode;
		pNode = pNode->pNext;
	}

	pNode = pHead;
	while (nullptr != pNode)
	{
		if (nullptr == pNode->pNext)
			break;

		std::cout << pNode->nVal << " ";
		pNode = pNode->pNext;
	}
	std::cout << std::endl;

	pNode = Reverse(pHead);
	while (nullptr != pNode)
	{
		if (nullptr == pNode->pNext)
			break;

		std::cout << pNode->nVal << " ";
		pNode = pNode->pNext;
	}
	std::cout << std::endl;

	std::system("pause");
	return 0;
}