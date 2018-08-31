#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
	int x;
	int y;
}Point2D;   // Point2D �ṹ

typedef struct
{
	Point2D *pt;   //���Ա��������
	int length;    //���Ա�ǰ����
	int size;      //���Ա�������
}ArrList;   // ArrList �ṹ


			//�������Ա������еķ���
ArrList *CreateArrList(int nLength);       //������Ϊ nArrLength �����Ա�
void DestroyArrList(ArrList *pArrList);    //�������Ա� pArrList
void ClearArrList(ArrList *pArrList);      //�ÿ����Ա� pArrList
int IsEmptyArrList(ArrList *pArrList);     //������Ա��Ƿ�Ϊ��
int GetArrListLength(ArrList *pArrList);   //��ȡ���Ա���
int GetArrListSize(ArrList *pArrList);     //��ȡ���Ա�������
int GetArrListElement(ArrList *pArrList, int n, Point2D *pt);   //��ȡ���Ա��е�n��Ԫ��
int FindElement(ArrList *pArrList, int nPos, Point2D *pt);      //�� nPos ����� pt ��һ�γ��ֵ�λ��
int GetPriorElement(ArrList *pArrList, Point2D *pt, Point2D *prior_pt);   //��ȡ pt ��ǰ���ڵ㵽 prior_pt
int GetNextElement(ArrList *pArrList, Point2D *pt, Point2D *next_pt);     //��ȡ pt �ĺ�̽ڵ㵽 next_pt
int AppendToArrList(ArrList *pArrList, Point2D *pt);            //�� pt ��ӵ����Ա�ĩβ��
int InsertToArrList(ArrList *pArrList, int nPos, Point2D *pt);  //�� pt ���뵽 nPos ��
int DeleteFromArrList(ArrList *pArrList, int nPos);             //ɾ�����Ա���λ��Ϊ nPos ��Ԫ��
void ForEachArrList(ArrList *pArrList, void(*func)(Point2D *pt));              //�����Ա���ÿ��Ԫ��ִ�� func ����
int ArrListCpy(ArrList *pArrListDest, ArrList *pArrListSrc);    //�����Ա� pArrListSrc ���Ƶ� pArrListDest
int ArrListCat(ArrList *pArrListDest, ArrList *pArrListSrc);    //�����Ա� pArrListSrc ���ӵ� pArrListDest ��ĩβ


																//���Ա���ʵ��
																/**
																* @brief ��������Ϊ nLength �����Ա� ArrList
																*
																* @param nLength ��Ҫ���������Ա���
																*
																* @return ָ�������������Ա��ָ��
																*/
ArrList *CreateArrList(int nLength)
{
	ArrList *pl = (ArrList *)malloc(sizeof(ArrList));

	pl->pt = (Point2D *)calloc(nLength, sizeof(Point2D));
	pl->length = nLength;
	pl->size = 0;

	return pl;
}


/**ͨ���ṹ��ָ����������ṹ������ĳ�Ա������һ����ʽ���£�
(*�ṹ��ָ�����).��Ա����
���С��ṹ��ָ�������Ϊ�ṹ��ָ�����������Ա������Ϊ�ṹ���Ա�������ƣ���.��Ϊȡ�ṹ���Ա�������������
����C�������������µ��������->����ͨ���ṹ��ָ�����ֱ�ӻ�ýṹ������ĳ�Ա������һ����ʽ���£�
�ṹ��ָ�����->��Ա����
���С��ṹ��ָ�������Ϊ�ṹ��ָ�����������Ա������Ϊ�ṹ���Ա�������ƣ���->��Ϊ�������


* @brief ����һ�����Ա�
*
* @param pArrList ָ����������Ա��ָ��
*
* @return void
*/
void DestroyArrList(ArrList *pArrList)
{
	free(pArrList->pt);   ///���ͷ����Ա�pt
	free(pArrList);       ///�������Ա�pArrList
}

/**
* @brief �ÿ�һ�����Ա�
*
* @param pArrList ָ����ÿ����Ա��ָ��
*
* @return void
*/
void ClearArrList(ArrList *pArrList)
{
	pArrList->length = 0;
}

/**
* @brief ������Ա��Ƿ�Ϊ��
*
* @param pArrList ָ���������Ա��ָ��
*
* @return Ϊ���򷵻� TRUE, ���򷵻� FALSE
*/
int IsEmptyArrList(ArrList *pArrList)
{
	return pArrList->length == 0 ? TRUE : FALSE;
}

/**
* @brief ��ȡ���Ա���
*
* @param pArrList ָ�����ȡ���ȵ����Ա��ָ��
*
* @return ���ػ�ȡ�������Ա���
*/
int GetArrListLength(ArrList *pArrList)
{
	return pArrList->length;
}

/**
* @brief ��ȡ���Ա�������
*
* @param pArrList ָ�����ȡ���������Ա��ָ��
*
* @return ���ػ�ȡ�������Ա��������
*/
int GetArrListSize(ArrList *pArrList)
{
	return pArrList->size;
}

/**
* @brief ��ȡ���Ա��е� n ��Ԫ��
*
* @param pArrList ָ�����ȡ���е�Ԫ�ص����Ա��ָ��
* @param n Ҫ��ȡ�ĵ� n ��Ԫ��
* @param pt ���ڴ�Ż�ȡ����Ԫ�ص�ֵ�� Point2D ����ָ��
*
* @return ��ȡ�ɹ����� TRUE, ���򷵻� FALSE
*
* @note Ԫ��n, n �� 0 ��
*/
int GetArrListElement(ArrList *pArrList, int n, Point2D *pt)
{
	if (n < 0 || n > pArrList->length - 1)
		return FALSE;

	pt->x = pArrList->pt[n].x;
	pt->y = pArrList->pt[n].y;

	return TRUE;
}

/**
* @brief �� nPos ������Ԫ�� pt ��һ�γ��ֵ�λ��
*
* @param pArrList ָ����������е�Ԫ�ص����Ա��ָ��
* @param nPos ������ʼλ��
* @param pt ָ�������Ԫ�ص�ָ��
*
* @return ���ҵ�, ����Ԫ�� pt �����Ա��е�λ��(�±�), ���򷵻� -1
*
* @note λ�ô� 0 ����
*/
int FindElement(ArrList *pArrList, int nPos, Point2D *pt)
{
	int n = nPos;
	for (n; n < pArrList->length; ++n)
	{
		if ((pArrList->pt[n].x == pt->x) && (pArrList->pt[n].y == pt->y))
			return n;
	}

	return -1;
}

/**
* @brief ��ȡ���Ա��� pt Ԫ�ص�ǰ���ڵ㵽 prior_pt
*
* @param pArrList ָ�����ȡ���е�Ԫ�ص����Ա��ָ��
* @param pt ָ��Ŀ��ڵ��ָ��
* @param prior_pt ��Ų��ҵ���Ŀ��ڵ��ǰ���ڵ�
*
* @return ����ȡ��ǰ���ڵ�, ����Ŀ��ڵ��ǰ���ڵ������Ա��е�λ��(�±�),  ���򷵻� -1
*
* @note λ�ô� 0 ����
*/
int GetPriorElement(ArrList *pArrList, Point2D *pt, Point2D *prior_pt)
{
	int n = 0;
	for (n = 0; n < pArrList->length; ++n)
	{
		if ((pArrList->pt[n].x == pt->x) && (pArrList->pt[n].y == pt->y))
		{
			if (n <= 0)        ///Ŀ��ڵ���ͷ�ڵ�, ��ǰ���ڵ�
				return -1;
			else                ///���ڲ��ҵ�ǰ���ڵ�
			{
				prior_pt->x = pArrList->pt[n - 1].x;
				prior_pt->y = pArrList->pt[n - 1].y;

				return n - 1;
			}
		}
	}

	return -1;
}

/**
* @brief ��ȡ���Ա��� pt Ԫ�صĺ�̽ڵ㵽 next_pt
*
* @param pArrList ָ�����ȡ���е�Ԫ�ص����Ա��ָ��
* @param pt ָ��Ŀ��ڵ��ָ��
* @param next_pt ��Ų��ҵ���Ŀ��ڵ�ĺ�̽ڵ�
*
* @return ����ȡ����̽ڵ�, ����Ŀ��ڵ�ĺ�̽ڵ������Ա��е�λ��(�±�),  ���򷵻� -1
*
* @note λ�ô� 0 ����
*/
int GetNextElement(ArrList *pArrList, Point2D *pt, Point2D *next_pt)
{
	int n = 0;
	for (n = 0; n < pArrList->length; ++n)
	{
		if ((pArrList->pt[n].x == pt->x) && (pArrList->pt[n].y == pt->y))
		{
			if (n >= pArrList->length - 1)        ///Ŀ��ڵ���β�ڵ�, �޺�̽ڵ�
				return -1;
			else                ///���ڲ��ҵ���̽ڵ�
			{
				next_pt->x = pArrList->pt[n + 1].x;
				next_pt->y = pArrList->pt[n + 1].y;

				return n + 1;
			}
		}
	}

	return -1;
}

/**
* @brief ���һ��Ԫ�������Ա�ĩβ
*
* @param pArrList ָ������Ԫ�ص����Ա��ָ��
* @param pt ָ�����ӵ�Ԫ�ص�ָ��
*
* @return �ɹ�����򷵻ص�ǰ���Ա���, ���򷵻� -1
*/
int AppendToArrList(ArrList *pArrList, Point2D *pt)
{
	if (pArrList->size - pArrList->length < 1) ///����Ƿ���Ҫ����
	{
		Point2D *p = (Point2D *)calloc(pArrList->length * 2, sizeof(Point2D));
		memcpy(p, pArrList->pt, pArrList->length * sizeof(Point2D));
		pArrList->size = pArrList->length * 2;
		free(pArrList->pt);
		pArrList->pt = p;
	}

	pArrList->pt[pArrList->length].x = pt->x;
	pArrList->pt[pArrList->length].y = pt->y;

	return ++pArrList->length;
}

/**
* @brief ����һ��Ԫ�� pt �����Ա� nPos ��
*
* @param pArrList ָ�������Ԫ�ص����Ա�ָ��
* @param nPos �����λ��(�±�)
* @param pt ָ��������Ԫ�ص�ָ��
*
* @return ����ɹ��򷵻ص�ǰ���Ա���, ���򷵻� -1
*
* @note ����λ�� nPos �� 0 ����
*/
int InsertToArrList(ArrList *pArrList, int nPos, Point2D *pt)
{
	if ((nPos < 0) || (nPos > pArrList->length - 1))
		return -1;

	if (pArrList->size - pArrList->length < 1) ///����Ƿ���Ҫ����
	{
		Point2D *p = (Point2D *)calloc(pArrList->length * 2, sizeof(Point2D));
		memcpy(p, pArrList->pt, pArrList->length * sizeof(Point2D));
		pArrList->size = pArrList->length * 2;
		free(pArrList->pt);
		pArrList->pt = p;
	}

	int nMax = pArrList->length;                ///��ȡ���Ա����1Ԫ�غ�ĳ���
	for (nMax; nMax > nPos; --nMax)
	{
		pArrList->pt[nMax].x = pArrList->pt[nMax - 1].x;
		pArrList->pt[nMax].y = pArrList->pt[nMax - 1].y;
	}
	pArrList->pt[nPos].x = pt->x;
	pArrList->pt[nPos].y = pt->y;

	return ++pArrList->length;
}

/**
* @brief �����Ա���ɾ��һ��Ԫ��
*
* @param pArrList ָ����������Ա��ָ��
* @param nPos ��Ҫɾ����Ԫ��λ��(�±�)
*
* @return �ɹ�ɾ������ɾ�������Ա���, ���򷵻� -1
*
* @note ɾ��λ�� nPos �� 0 ����
*/
int DeleteFromArrList(ArrList *pArrList, int nPos)
{
	if ((nPos < 0) || (nPos > pArrList->length - 1))
		return -1;

	if (nPos == pArrList->length - 1)
		return --pArrList->length;

	for (nPos; nPos < pArrList->length; ++nPos)
	{
		pArrList->pt[nPos].x = pArrList->pt[nPos + 1].x;
		pArrList->pt[nPos].y = pArrList->pt[nPos + 1].y;
	}

	return --pArrList->length;
}

/**
* @brief �����Ա��е�Ԫ������ִ�д���ĺ���
*
* @param pArrList ָ�����������Ա��ָ��
* @param func ����ĺ���ָ��
*
* @return void
*
* @note ����ĺ����Ĳ���Ϊ���Ա�Ԫ�����͵�ָ��
*/
void ForEachArrList(ArrList *pArrList, void(*func)(Point2D *pt))
{
	int i = 0;
	for (i = 0; i < pArrList->length; ++i)
	{
		func(&pArrList->pt[i]);
	}
}

/**
* @brief �����Ա� pArrListSrc ���Ƶ�Ŀ�����Ա� pArrListDest
*
* @param pArrListDest Ŀ�����Ա�
* @param pArrListSrc Դ���Ա�
*
* @return �ɹ��򷵻ظ��ƺ��Ŀ�����Ա�ĳ���, ���򷵻� -1
*/
int ArrListCpy(ArrList *pArrListDest, ArrList *pArrListSrc)
{
	if (pArrListDest->size - pArrListSrc->length < 0)  ///Ŀ�����Ա��Ƿ���Ҫ����
	{
		free(pArrListDest->pt);
		Point2D *p = (Point2D *)calloc(pArrListSrc->length, sizeof(Point2D));
		pArrListDest->pt = p;
		pArrListDest->size = pArrListSrc->length;
	}

	memcpy(pArrListDest->pt, pArrListSrc->pt, pArrListSrc->length * sizeof(Point2D));
	pArrListDest->length = pArrListSrc->length;

	return pArrListDest->length;
}

/**
* @brief �����Ա� pArrListSrc ���ӵ�Ŀ�����Ա� pArrListDest
*
* @param pArrListDest Ŀ�����Ա�
* @param pArrListSrc Դ���Ա�
*
* @return �ɹ��򷵻����Ӻ��Ŀ�����Ա�ĳ���, ���򷵻� -1
*/
int ArrListCat(ArrList *pArrListDest, ArrList *pArrListSrc)
{
	if (pArrListDest->size - pArrListDest->length < pArrListSrc->length)   ///Ŀ�����Ա��Ƿ���Ҫ����
	{
		Point2D *p = (Point2D *)calloc(pArrListDest->length + pArrListSrc->length, sizeof(Point2D));
		memcpy(p, pArrListDest->pt, pArrListDest->length * sizeof(Point2D));
		free(pArrListDest->pt);
		pArrListDest->pt = p;
		pArrListDest->size = pArrListDest->length + pArrListSrc->length;
	}

	int pos = 0;
	for (pos; pos < pArrListSrc->length; ++pos)
	{
		pArrListDest->pt[pArrListDest->length + pos].x = pArrListSrc->pt[pos].x;
		pArrListDest->pt[pArrListDest->length + pos].y = pArrListSrc->pt[pos].y;
	}

	pArrListDest->length += pArrListSrc->length;

	return pArrListDest->length;
}

//�������Ա� ArrList

//�ص�����
void display(Point2D *pt)
{
	printf("(%d,%d) ", pt->x, pt->y);
}

int main()
{
	Point2D pt1, pt2;
	ArrList *plstA = CreateArrList(10);        //����һ������Ϊ 10 �����Ա� plstA

											   ///
	printf("�������Ԫ��..\n");
	int i = 0;
	for (i; i < 10; ++i)
	{
		pt1.x = i; pt1.y = i;
		AppendToArrList(plstA, &pt1);         //�������
	}
	ForEachArrList(plstA, display);           //��ÿ��Ԫ��ִ�� display
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n���Ա����������..\n");
	for (i = 10; i < 35; ++i)
	{
		pt1.x = i; pt1.y = i;
		AppendToArrList(plstA, &pt1);         //���Ա�������
	}
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n���Բ��뵽ͷ����β��..\n");
	pt1.x = 100; pt1.y = 100;
	InsertToArrList(plstA, 0, &pt1);             //���Բ��뵽�ײ�
	InsertToArrList(plstA, GetArrListLength(plstA) - 1, &pt1);             //���Բ��뵽β��
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n���Ի�ȡ�ڵ�Ԫ��..\n");
	GetArrListElement(plstA, 5, &pt2);           //��ȡ�ڵ�λ��Ϊ5��Ԫ��
	printf("�ڵ�����Ϊ5��Ԫ��pt2: (%d,%d)\n", pt2.x, pt2.y);

	///
	printf("\n���Ի�ȡĳԪ�ص�ǰ���ڵ�..\n");
	Point2D pri_pt, next_pt;
	GetPriorElement(plstA, &pt2, &pri_pt);       //��ȡ pt2 ��ǰ���ڵ�
	printf("pt2��ǰ���ڵ�: (%d, %d)\n", pri_pt.x, pri_pt.y);
	GetNextElement(plstA, &pt2, &next_pt);       //��ȡ pt2 �ĺ�̽ڵ�
	printf("pt2�ĺ�̽ڵ�: (%d, %d)\n", next_pt.x, next_pt.y);

	///
	printf("\n���Բ���Ԫ��..\n");
	printf("Ԫ�� next_pt �����Ա��е�һ�γ��ֵ�λ��: %d\n", FindElement(plstA, 0, &next_pt));  //�� 0 �����Ԫ�� next_pt

																				///
	printf("\n����ɾ��ĳԪ��..\n");
	printf("ɾ��λ��Ϊ0��Ԫ��: ");
	DeleteFromArrList(plstA, 0);      //ɾ���ڵ�λ��Ϊ0��Ԫ��
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n���Ը������Ա�..\n");
	printf("�������Ա� plstB : ");
	ArrList *plstB = CreateArrList(50);
	for (i = 50; i < 60; ++i)
	{
		pt2.x = i; pt2.y = i;
		AppendToArrList(plstB, &pt2);
	}
	ForEachArrList(plstB, display);
	printf("\nplstB len = %d, size = %d\n", GetArrListLength(plstB), GetArrListSize(plstB));
	printf("�� plstB ���Ƶ� plstA: \n");
	ArrListCpy(plstA, plstB);             //�����Ա� plstB ���Ƶ� plstA
	ForEachArrList(plstA, display);
	printf("plstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n�����������Ա�..\n");
	printf("�� plstB ���ӵ� plstA: ");
	ArrListCat(plstA, plstB);             //�����Ա� plstB ���ӵ� plstA
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n����������Ա�..\n");
	ClearArrList(plstA);                  //������Ա� plstA
	ForEachArrList(plstA, display);
	printf("plstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));
	printf("IsEmpty = %d\n", IsEmptyArrList(plstA));

	///
	printf("\n�������Ա�..\n");
	DestroyArrList(plstA);        //�������Ա�, �ͷ���Դ
	DestroyArrList(plstB);



	/**
	ArrList *CreateArrList(int nLength);       //������Ϊ nArrLength �����Ա�
	void DestroyArrList(ArrList *pArrList);    //�������Ա� pArrList
	void ClearArrList(ArrList *pArrList);      //�ÿ����Ա� pArrList
	int IsEmptyArrList(ArrList *pArrList);     //������Ա��Ƿ�Ϊ��
	int GetArrListLength(ArrList *pArrList);   //��ȡ���Ա���
	int GetArrListSize(ArrList *pArrList);     //��ȡ���Ա�������
	int GetArrListElement(ArrList *pArrList, int n, Point2D *pt);   //��ȡ���Ա��е�n��Ԫ��
	int FindElement(ArrList *pArrList, int nPos, Point2D *pt);      //�� nPos ����� pt ��һ�γ��ֵ�λ��
	int GetPriorElement(ArrList *pArrList, Point2D *pt, Point2D *prior_pt);   //��ȡ pt ��ǰ���ڵ㵽 prior_pt
	int GetNextElement(ArrList *pArrList, Point2D *pt, Point2D *next_pt);     //��ȡ pt �ĺ�̽ڵ㵽 next_pt
	int AppendToArrList(ArrList *pArrList, Point2D *pt);            //�� pt ��ӵ����Ա�ĩβ��
	int InsertToArrList(ArrList *pArrList, int nPos, Point2D *pt);  //�� pt ���뵽 nPos ��
	int DeleteFromArrList(ArrList *pArrList, int nPos);             //ɾ�����Ա���λ��Ϊ nPos ��Ԫ��
	void ForEachArrList(ArrList *pArrList, void(*func)(Point2D *pt));              //�����Ա���ÿ��Ԫ��ִ�� func ����
	int ArrListCpy(ArrList *pArrListDest, ArrList *pArrListSrc);    //�����Ա� pArrListSrc ���Ƶ� pArrListDest
	int ArrListCat(ArrList *pArrListDest, ArrList *pArrListSrc);    //�����Ա� pArrListSrc ���ӵ� pArrListDest ��ĩβ
	*/

	printf("//////////////////////////////////Musk's program begining///////////////////////////////////////");
	Point2D cg1,cg2;

	cg1.x = 0;
	cg1.y = 0;
	ArrList *Musk = CreateArrList(100);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(Musk), GetArrListSize(Musk));
	int j;

	for (int i = 1; i <= GetArrListLength(Musk);i++) {
		DeleteFromArrList(Musk, i);
		InsertToArrList(Musk, i,&cg1);
		cg1.x++;
		j = GetArrListElement(Musk, i, &cg2);
		printf("The %dth number in the list is the %d \n", i, cg2.x);
	}
	int h;
	printf("����Ҫ�ڼ�����ֵ��");
	scanf_s("\n%d",&h);
	j = GetArrListElement(Musk, h, &cg2);
	printf("The number %dth number in the list is the %d \n", h,cg2.x);
	getchar();
	getchar();
	getchar();

	return 0;
}