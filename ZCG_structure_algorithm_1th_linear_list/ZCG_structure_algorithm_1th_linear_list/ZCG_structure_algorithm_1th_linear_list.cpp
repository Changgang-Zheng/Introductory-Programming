#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
	int x;
	int y;
}Point2D;   // Point2D 结构

typedef struct
{
	Point2D *pt;   //线性表的数据项
	int length;    //线性表当前长度
	int size;      //线性表总容量
}ArrList;   // ArrList 结构


			//声明线性表所具有的方法
ArrList *CreateArrList(int nLength);       //创建长为 nArrLength 的线性表
void DestroyArrList(ArrList *pArrList);    //销毁线性表 pArrList
void ClearArrList(ArrList *pArrList);      //置空线性表 pArrList
int IsEmptyArrList(ArrList *pArrList);     //检测线性表是否为空
int GetArrListLength(ArrList *pArrList);   //获取线性表长度
int GetArrListSize(ArrList *pArrList);     //获取线性表总容量
int GetArrListElement(ArrList *pArrList, int n, Point2D *pt);   //获取线性表中第n个元素
int FindElement(ArrList *pArrList, int nPos, Point2D *pt);      //从 nPos 起查找 pt 第一次出现的位置
int GetPriorElement(ArrList *pArrList, Point2D *pt, Point2D *prior_pt);   //获取 pt 的前驱节点到 prior_pt
int GetNextElement(ArrList *pArrList, Point2D *pt, Point2D *next_pt);     //获取 pt 的后继节点到 next_pt
int AppendToArrList(ArrList *pArrList, Point2D *pt);            //将 pt 添加到线性表末尾处
int InsertToArrList(ArrList *pArrList, int nPos, Point2D *pt);  //将 pt 插入到 nPos 处
int DeleteFromArrList(ArrList *pArrList, int nPos);             //删除线性表上位置为 nPos 的元素
void ForEachArrList(ArrList *pArrList, void(*func)(Point2D *pt));              //对线性表中每个元素执行 func 函数
int ArrListCpy(ArrList *pArrListDest, ArrList *pArrListSrc);    //将线性表 pArrListSrc 复制到 pArrListDest
int ArrListCat(ArrList *pArrListDest, ArrList *pArrListSrc);    //将线性表 pArrListSrc 连接到 pArrListDest 的末尾


																//线性表方法实现
																/**
																* @brief 创建长度为 nLength 的线性表 ArrList
																*
																* @param nLength 所要构建的线性表长度
																*
																* @return 指向所创建的线性表的指针
																*/
ArrList *CreateArrList(int nLength)
{
	ArrList *pl = (ArrList *)malloc(sizeof(ArrList));

	pl->pt = (Point2D *)calloc(nLength, sizeof(Point2D));
	pl->length = nLength;
	pl->size = 0;

	return pl;
}


/**通过结构体指针变量获得其结构体变量的成员变量的一般形式如下：
(*结构体指针变量).成员变量
其中“结构体指针变量”为结构体指针变量，“成员变量”为结构体成员变量名称，“.”为取结构体成员变量的运算符。
另外C语言中引入了新的运算符“->”，通过结构体指针变量直接获得结构体变量的成员变量，一般形式如下：
结构体指针变量->成员变量
其中“结构体指针变量”为结构体指针变量，“成员变量”为结构体成员变量名称，“->”为运算符。


* @brief 销毁一条线性表
*
* @param pArrList 指向待销毁线性表的指针
*
* @return void
*/
void DestroyArrList(ArrList *pArrList)
{
	free(pArrList->pt);   ///先释放线性表pt
	free(pArrList);       ///销毁线性表pArrList
}

/**
* @brief 置空一条线性表
*
* @param pArrList 指向待置空线性表的指针
*
* @return void
*/
void ClearArrList(ArrList *pArrList)
{
	pArrList->length = 0;
}

/**
* @brief 检测线性表是否为空
*
* @param pArrList 指向待检测线性表的指针
*
* @return 为空则返回 TRUE, 否则返回 FALSE
*/
int IsEmptyArrList(ArrList *pArrList)
{
	return pArrList->length == 0 ? TRUE : FALSE;
}

/**
* @brief 获取线性表长度
*
* @param pArrList 指向待获取长度的线性表的指针
*
* @return 返回获取到的线性表长度
*/
int GetArrListLength(ArrList *pArrList)
{
	return pArrList->length;
}

/**
* @brief 获取线性表总容量
*
* @param pArrList 指向待获取容量的线性表的指针
*
* @return 返回获取到的线性表的总容量
*/
int GetArrListSize(ArrList *pArrList)
{
	return pArrList->size;
}

/**
* @brief 获取线性表中第 n 个元素
*
* @param pArrList 指向待获取其中的元素的线性表的指针
* @param n 要获取的第 n 个元素
* @param pt 用于存放获取到的元素的值的 Point2D 类型指针
*
* @return 获取成功返回 TRUE, 否则返回 FALSE
*
* @note 元素n, n 从 0 起
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
* @brief 从 nPos 处查找元素 pt 第一次出现的位置
*
* @param pArrList 指向待查找其中的元素的线性表的指针
* @param nPos 查找起始位置
* @param pt 指向待查找元素的指针
*
* @return 若找到, 返回元素 pt 在线性表中的位置(下标), 否则返回 -1
*
* @note 位置从 0 计起
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
* @brief 获取线性表中 pt 元素的前驱节点到 prior_pt
*
* @param pArrList 指向待获取其中的元素的线性表的指针
* @param pt 指向目标节点的指针
* @param prior_pt 存放查找到的目标节点的前驱节点
*
* @return 若获取到前驱节点, 返回目标节点的前驱节点在线性表中的位置(下标),  否则返回 -1
*
* @note 位置从 0 计起
*/
int GetPriorElement(ArrList *pArrList, Point2D *pt, Point2D *prior_pt)
{
	int n = 0;
	for (n = 0; n < pArrList->length; ++n)
	{
		if ((pArrList->pt[n].x == pt->x) && (pArrList->pt[n].y == pt->y))
		{
			if (n <= 0)        ///目标节点是头节点, 无前驱节点
				return -1;
			else                ///存在并找到前驱节点
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
* @brief 获取线性表中 pt 元素的后继节点到 next_pt
*
* @param pArrList 指向待获取其中的元素的线性表的指针
* @param pt 指向目标节点的指针
* @param next_pt 存放查找到的目标节点的后继节点
*
* @return 若获取到后继节点, 返回目标节点的后继节点在线性表中的位置(下标),  否则返回 -1
*
* @note 位置从 0 计起
*/
int GetNextElement(ArrList *pArrList, Point2D *pt, Point2D *next_pt)
{
	int n = 0;
	for (n = 0; n < pArrList->length; ++n)
	{
		if ((pArrList->pt[n].x == pt->x) && (pArrList->pt[n].y == pt->y))
		{
			if (n >= pArrList->length - 1)        ///目标节点是尾节点, 无后继节点
				return -1;
			else                ///存在并找到后继节点
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
* @brief 添加一个元素至线性表末尾
*
* @param pArrList 指向待添加元素的线性表的指针
* @param pt 指向待添加的元素的指针
*
* @return 成功添加则返回当前线性表长度, 否则返回 -1
*/
int AppendToArrList(ArrList *pArrList, Point2D *pt)
{
	if (pArrList->size - pArrList->length < 1) ///检测是否需要扩容
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
* @brief 插入一个元素 pt 到线性表 nPos 处
*
* @param pArrList 指向待插入元素的线性表指针
* @param nPos 插入的位置(下标)
* @param pt 指向待插入的元素的指针
*
* @return 插入成功则返回当前线性表长度, 否则返回 -1
*
* @note 插入位置 nPos 从 0 计起
*/
int InsertToArrList(ArrList *pArrList, int nPos, Point2D *pt)
{
	if ((nPos < 0) || (nPos > pArrList->length - 1))
		return -1;

	if (pArrList->size - pArrList->length < 1) ///检测是否需要扩容
	{
		Point2D *p = (Point2D *)calloc(pArrList->length * 2, sizeof(Point2D));
		memcpy(p, pArrList->pt, pArrList->length * sizeof(Point2D));
		pArrList->size = pArrList->length * 2;
		free(pArrList->pt);
		pArrList->pt = p;
	}

	int nMax = pArrList->length;                ///获取线性表插入1元素后的长度
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
* @brief 从线性表上删除一个元素
*
* @param pArrList 指向待处理线性表的指针
* @param nPos 需要删除的元素位置(下标)
*
* @return 成功删除返回删除后线性表长度, 否则返回 -1
*
* @note 删除位置 nPos 从 0 计起
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
* @brief 对线性表中的元素依次执行传入的函数
*
* @param pArrList 指向待处理的线性表的指针
* @param func 传入的函数指针
*
* @return void
*
* @note 传入的函数的参数为线性表元素类型的指针
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
* @brief 将线性表 pArrListSrc 复制到目标线性表 pArrListDest
*
* @param pArrListDest 目标线性表
* @param pArrListSrc 源线性表
*
* @return 成功则返回复制后的目标线性表的长度, 否则返回 -1
*/
int ArrListCpy(ArrList *pArrListDest, ArrList *pArrListSrc)
{
	if (pArrListDest->size - pArrListSrc->length < 0)  ///目标线性表是否需要扩容
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
* @brief 将线性表 pArrListSrc 连接到目标线性表 pArrListDest
*
* @param pArrListDest 目标线性表
* @param pArrListSrc 源线性表
*
* @return 成功则返回连接后的目标线性表的长度, 否则返回 -1
*/
int ArrListCat(ArrList *pArrListDest, ArrList *pArrListSrc)
{
	if (pArrListDest->size - pArrListDest->length < pArrListSrc->length)   ///目标线性表是否需要扩容
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

//测试线性表 ArrList

//回调函数
void display(Point2D *pt)
{
	printf("(%d,%d) ", pt->x, pt->y);
}

int main()
{
	Point2D pt1, pt2;
	ArrList *plstA = CreateArrList(10);        //创建一个长度为 10 的线性表 plstA

											   ///
	printf("测试添加元素..\n");
	int i = 0;
	for (i; i < 10; ++i)
	{
		pt1.x = i; pt1.y = i;
		AppendToArrList(plstA, &pt1);         //测试添加
	}
	ForEachArrList(plstA, display);           //对每个元素执行 display
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n测试被动扩容添加..\n");
	for (i = 10; i < 35; ++i)
	{
		pt1.x = i; pt1.y = i;
		AppendToArrList(plstA, &pt1);         //测试被动扩容
	}
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n测试插入到头部、尾部..\n");
	pt1.x = 100; pt1.y = 100;
	InsertToArrList(plstA, 0, &pt1);             //测试插入到首部
	InsertToArrList(plstA, GetArrListLength(plstA) - 1, &pt1);             //测试插入到尾部
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n测试获取节点元素..\n");
	GetArrListElement(plstA, 5, &pt2);           //获取节点位置为5的元素
	printf("节点坐标为5的元素pt2: (%d,%d)\n", pt2.x, pt2.y);

	///
	printf("\n测试获取某元素的前驱节点..\n");
	Point2D pri_pt, next_pt;
	GetPriorElement(plstA, &pt2, &pri_pt);       //获取 pt2 的前驱节点
	printf("pt2的前驱节点: (%d, %d)\n", pri_pt.x, pri_pt.y);
	GetNextElement(plstA, &pt2, &next_pt);       //获取 pt2 的后继节点
	printf("pt2的后继节点: (%d, %d)\n", next_pt.x, next_pt.y);

	///
	printf("\n测试查找元素..\n");
	printf("元素 next_pt 在线性表中第一次出现的位置: %d\n", FindElement(plstA, 0, &next_pt));  //从 0 起查找元素 next_pt

																				///
	printf("\n测试删除某元素..\n");
	printf("删除位置为0的元素: ");
	DeleteFromArrList(plstA, 0);      //删除节点位置为0的元素
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n测试复制线性表..\n");
	printf("创建线性表 plstB : ");
	ArrList *plstB = CreateArrList(50);
	for (i = 50; i < 60; ++i)
	{
		pt2.x = i; pt2.y = i;
		AppendToArrList(plstB, &pt2);
	}
	ForEachArrList(plstB, display);
	printf("\nplstB len = %d, size = %d\n", GetArrListLength(plstB), GetArrListSize(plstB));
	printf("将 plstB 复制到 plstA: \n");
	ArrListCpy(plstA, plstB);             //将线性表 plstB 复制到 plstA
	ForEachArrList(plstA, display);
	printf("plstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n测试连接线性表..\n");
	printf("将 plstB 连接到 plstA: ");
	ArrListCat(plstA, plstB);             //将线性表 plstB 连接到 plstA
	ForEachArrList(plstA, display);
	printf("\nplstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));

	///
	printf("\n测试清空线性表..\n");
	ClearArrList(plstA);                  //清空线性表 plstA
	ForEachArrList(plstA, display);
	printf("plstA len = %d, size = %d\n", GetArrListLength(plstA), GetArrListSize(plstA));
	printf("IsEmpty = %d\n", IsEmptyArrList(plstA));

	///
	printf("\n销毁线性表..\n");
	DestroyArrList(plstA);        //销毁线性表, 释放资源
	DestroyArrList(plstB);



	/**
	ArrList *CreateArrList(int nLength);       //创建长为 nArrLength 的线性表
	void DestroyArrList(ArrList *pArrList);    //销毁线性表 pArrList
	void ClearArrList(ArrList *pArrList);      //置空线性表 pArrList
	int IsEmptyArrList(ArrList *pArrList);     //检测线性表是否为空
	int GetArrListLength(ArrList *pArrList);   //获取线性表长度
	int GetArrListSize(ArrList *pArrList);     //获取线性表总容量
	int GetArrListElement(ArrList *pArrList, int n, Point2D *pt);   //获取线性表中第n个元素
	int FindElement(ArrList *pArrList, int nPos, Point2D *pt);      //从 nPos 起查找 pt 第一次出现的位置
	int GetPriorElement(ArrList *pArrList, Point2D *pt, Point2D *prior_pt);   //获取 pt 的前驱节点到 prior_pt
	int GetNextElement(ArrList *pArrList, Point2D *pt, Point2D *next_pt);     //获取 pt 的后继节点到 next_pt
	int AppendToArrList(ArrList *pArrList, Point2D *pt);            //将 pt 添加到线性表末尾处
	int InsertToArrList(ArrList *pArrList, int nPos, Point2D *pt);  //将 pt 插入到 nPos 处
	int DeleteFromArrList(ArrList *pArrList, int nPos);             //删除线性表上位置为 nPos 的元素
	void ForEachArrList(ArrList *pArrList, void(*func)(Point2D *pt));              //对线性表中每个元素执行 func 函数
	int ArrListCpy(ArrList *pArrListDest, ArrList *pArrListSrc);    //将线性表 pArrListSrc 复制到 pArrListDest
	int ArrListCat(ArrList *pArrListDest, ArrList *pArrListSrc);    //将线性表 pArrListSrc 连接到 pArrListDest 的末尾
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
	printf("你想要第几个数值？");
	scanf_s("\n%d",&h);
	j = GetArrListElement(Musk, h, &cg2);
	printf("The number %dth number in the list is the %d \n", h,cg2.x);
	getchar();
	getchar();
	getchar();

	return 0;
}