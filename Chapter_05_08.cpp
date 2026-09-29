/* 执行时弹出警告"该文件包含不能在当前代码页...请将该文件..."属于正常情况,因为文档内中文注释过多 */
/* 修复警告则点击右下角的编码,选择"通过编码重新打开",选择"Unicode(UTF-8带签名)-代码页65001" */
/* 此处推荐一个子体Maple Mono Normal NL NF CN,真的很好看 */

// 以下内容基于Windows平台实现,运行软件为Visual Studio 2026,环境为32位(在上方修改为x86)
// 对于"/**/"注释,仅做拓展说明或占位行,无需深入研究

#include "Chapter_05_08.h"

using std::cout;
using std::endl;
using std::string;

// 第5章
void Adv01_for()
{
	using namespace std;
	// 循环可以轻松的执行重复的任务
	int limit = 2;
	int i;
	for (i = limit; i; i--)
	// for循环格式:
	// for (init-expression; test-expression; update-expression)
	//     body;
		// init-expression 初始化表达式,循环开始前初始化参与循环的变量
		// test-expression 测试表达式,决定循环体是否被执行
			// 测试表达式的判定与bool的字面值有关
			// 对于判断式,若表达式为true(值为1),则继续执行循环;0值为false(值为0),则停止执行循环
			// 此处的"i"默认为"i<0"
		// update-expression 更新表达式,在每轮循环结束时执行
		cout << "i = " << i << "\n";
	cout << "Done now that i = " << i << "\n";
	//
	int x = 3;
	cout << (x = 3) << endl;
	cout << (x < 1) << endl;
	cout << boolalpha;
	cout << (x < 1) << endl;
	cout << noboolalpha;
	// 每一个这样的判断表达式都对应1或0的值,对应着bool值的true或false
	for (x; x < 3; x++)
		cout << "That's true?\n";
	// for语句不是表达式,它没有值,也不能给它赋值
	for (int x = 5; x <= 8; x++)
		cout << x << endl;
	cout << x;
	// 可以在for循环内声明变量,但该变量只在for循环内生效,不对for循环外内容产生任何影响
	// 此处for循环内部最后x=8,for循环外部x=3
	long long factorials[16];
	factorials[1] = factorials[0] = 1LL;
	for (int i = 2; i < 16; i++)
		factorials[i] = i * factorials[i - 1];
	for (int i = 0; i < 16; i++)
		cout << i << "! = " << factorials[i] << endl;
	// 数组可以通过for循环来添加,修改或删减元素
	int by;
	cin >> by;
	cout << "Counting by " << by << "s:\n";
	for (int i = 0; i < 100; i = i + by)
		cout << i << endl;
	// 更新表达式可以控制步长
	cout << "Enter a word: ";
	string word;
	cin >> word;
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << endl;
	// for循环可以访问字符串
	int a = 20, b = 20;
	cout << "a++ = " << a++ << "; ++b = " << ++b << endl;
	// "++","--"被称为递增/递减运算符
	// 下文仅对"++"进行讨论,"--"同理
	//
	// "++a","a++"分别为"a = a + 1"的前缀/后缀格式
	// ++a(常用):
	// 返回值为a+1,意为"先加后用"
	// 无需生成临时变量,直接在变量上进行加减操作
	// a++:
	// 返回值为a,意为"先用后加"
	// 需要生成临时值的副本,副本进行加减操作,返回临时变量的值
	double arr[5] = {21.1, 32.8, 23.4, 45.2, 37.4};
	double* pt = arr;
	cout << ++*pt << endl;
	// 对指针来说,++位置的不同代表的意义也不同
	// 此处意为++(*pt),前缀++先加后用
	// 过程:
	// *pt = arr[0], arr[0] = arr[0] + 1 = 22.1, 取值22.1,指针指向arr[0]
	cout << *++pt << endl;
	// 此处意为*(++pt),前缀++先加后用
	// 过程:
	// pt = pt + 1 -> arr[1], *pt = arr[1], 取值32.8, 指针指向arr[1]
	cout << (*pt)++ << endl;
	// 此处先用后加
	// 过程:
	// *pt = arr[1], 取值32.8, arr[1] = arr[1] + 1 = 33.8, 指针指向arr[1]
	cout << *pt++ << endl;
	// "后缀++"优先级更高,意为*(pt++),后缀++先用后加
	// 过程:
	// pt++产生当前地址对应值的副本*pt, *pt = arr[1], 取值33.8, pt = pt + 1 -> arr[2], 指针指向arr[2]
	// "前缀++"的优先级与"*"相同
}

void Adv02_Operators_Comparisons()
{
	// 组合赋值运算符可以更简洁的完成一些运算
		// 以下运算符默认左侧为L,右侧为R,如(L) += (R)
	// += 将 L+R 赋给 L
	// -= 将 L-R 赋给 L
	// *= 将 L*R 赋给 L
	// /= 将 L/R 赋给 L
	// %= 将 L%R 赋给 L
	int in1 = 5, in2 = in1 %= in1;
	cout << in2 << endl;
	//
	// for循环语句可以通过{}来包含任意多条语句
	for (int i = 1; i <= 5; i++)
	{
	// 此括号内的内容每进行1次循环便会执行1次
		cout << i << endl;
		cout << "Is it you first time see me?\n";
	}
	for (int i = 1; i <= 5; i++)
		cout << i << endl;
		cout << "Is it you first time see me?\n";
	// for后不加花括号的同时缩进,只会判定第1行缩进参与循环,后续缩进忽略
	int x = 20;
	{
		cout << x << endl;
		int x = 100;
		cout << x << endl;
	}
	// 没有for等语句时,单独一对花括号被称为复合语句
	// 复合语句内定义新变量时,新变量仅在内部可见
	// 复合语句内定义已有变量时,将在复合语句内暂时屏蔽原有变量,离开花括号时原有变量再次可见
	// 复合语句块执行完毕后,内部的变量将被释放
	string temp, word = "September";
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
		// ","允许将多条初始化或运算操作放到只允许放一个表达式的地方
	{
		temp[0] = word[i];
		word[i] = word[j];
		word[j] = temp[0];
	}
	cout << word;
	/* ","的运算优先级是最低的
	   在很特殊的情况下,逗号运算符会产生神奇的结果 */
		int r;
		r = 17,240;
		cout << r << endl;
		/* ","隔开了17与240, 所以会先计算r = 17 */
		r = (17,240);
		cout << r << endl;
		/* ","的运算规则是从左到右依次计算，但最终整个表达式的值是“最右边那个表达式的值”,所以会输出r = 240 */
	//
	// 关系运算符可以对数字进行比较
	// 比较结果为真,则值将为true(左边为主观);否则为false
	// <  小于
	// <= 小于或等于
	// == 等于
	// >  大于
	// >= 大于或等于
	// != 不等于
	int x2 = 10;
	bool cp = x2 + 5 != 5 - x2;
	cout << cp << endl;
	// 比较运算符优先级低于算术运算符
	cp = x2 == 4;
	x2 = 4;
	// "=="为比较运算符,"="为赋值运算符
	// 前者得到bool值,后者得到等式右边的值
	/*
		int arr1[5] = {1, 2, 3, 4, 5};
		for (int i = 0; arr1[i] = 6; i++)
			cout << arr1[i] << endl;
	*/
	// 此处的代码在没有外力干扰的情况下将不会停止
	// 若"="右边的值非0,则该表达式的bool值永远为true
	char ch = 'a';
	cp = ch < 'z';
	cout << cp << endl;
	// 关系运算符可以用来比较单个字符,因为单个字符对应其ASCII码
	// 关系运算符比较char数组没有实际意义,因为实际比较的是指针处的地址
	string mate = "?ate";
	char cmate[5] = "?ate";
	cout << bool(mate != "mate") << " " << bool(mate != cmate) << endl;
	// 关系运算符可以用于string对象
	// string对象可以与char数组进行比较,比较规则同strncmp
}

void Adv03_while()
{
	// while循环是没有初始化和更新表达式的for循环
	// while循环格式:
	// while (test-condition)
	//     body;
		// test-condition 测试条件表达式,若其bool值为true,则执行body操作,再返回对测试条件进行评估,如此循环
		// while循环停止只有测试条件bool值变为false,否则将一直进行下去
	// while无法生成临时变量,需要使用已定义变量
	char name[20] = "Alexander the Great";
	int ic = 0;
	while (name[ic])
		// 这里由于char字符的值为对应的编码,只有'\0'的对应值为0
		// 所以"name[ic]"等价于"name[ic] != '\0'"
	{
		cout << name[ic];
		++ic;
	}
	//
	// for ( ; ; )
	//     body
	// 上述for循环中的3个表达式都可以是空表达式,只有2个";"是必需的
	// 当测试表达式为空表达式时,测试结果为true,循环将一直运行下去
	//
	// 在C++中,for和while循环的本质是相同的
	for (int ir = 0; ir != 3; ++ir)
	{
		cout << "This sentence will be printed 3 times.\n";
	}

	int ir = 0;
	while (ir != 3)
	{
		cout << "This sentence will be printed 3 times.\n";
		++ir;
	}
	// for循环和while循环几乎等效,可以互相转换
	// for循环和while循环的主要区别:
	// 1.for循环括号内可以将3个表达式全写为空表达式
	//	 while循环的test-expression不能为空表达式
	// 2.for循环可以使用init-expression声明局部变量
	//	 while循环不能声明局部变量
	//
	while (name[ir] != '\0');
	// 请注意!!!在while循环后面放置";"将会导致程序进入死循环
	// name[ic] != '\0'的值为true,同时循环未对ic做任何操作
	// 该while循环为空语句,该循环将永远不执行任何操作
}

void Adv04_delay_typedef()
{
	using std::cin;
	// 通过使用头文件"ctime"中的函数来编写延时循环
	cout << "Enter the delay time, in seconds: ";
	float secs;
	cin >> secs;
	// 输入需要延时的秒数
	clock_t delay = secs * CLOCKS_PER_SEC;
	// CLOCKS_PER_SEC是一个常量,简单理解为系统时钟每秒跳动的次数
	// secs * CLOCKS_PER_SEC可以理解为延时secs秒系统时钟需要跳动的次数
	// clock_t是用来存储这个数据的类型
	cout << "starting\a\n";
	clock_t start = clock();
	// clock()函数会返回程序启动到现在的"时钟跳动数"
	// 此处clock()会随时间变化,start等于了固定值,不会随时间变化
	while (clock() - start < delay)
		;
	//循环将一直执行空语句直到clock()-start达到延迟时间
	cout << "delay done \a\n";
	//
	typedef long long twolong;
	twolong twl = 10000;
	// typedef可以为某种类型添加别名
	// typedef格式:
	// typedef typename aliasname
}

void Adv05_dowhile_rangefor()
{
	// do while循环先执行循环体,在判定测试表达式,决定是否继续执行循环
	// do while循环格式:
	// do
	// {
	//     body;
	// } while (test-expression);
	int n1 = 10;
	do
		cout << n1 << endl;
	while (n1 > 20);
	// 这里不满足测试表达式条件,但还是会执行1次循环体
	//
	double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
	for (double x : prices)
		cout << x << endl;
	// 该基于范围的for循环可以遍历数组中的每一个元素
	for (double& x : prices)
		x = x * 0.80;
	// 这种方法可以实现通过循环修改数组内元素
	/* 此处内容将会在后续章节介绍,无需过多注意 */
}

void Adv06_LoopsTest_Input()
{
	using std::cin;
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:\n";
	cin >> ch;
	while (ch != '#')
		// 此处"#"被称为哨兵字符,用来控制何时停止读取
	{
		cout << ch;
		++count;
		cin >> ch;
	}
	cout << endl << count << "characters read\n";
	// cin >>无法读取空格
	// 表现为此处输出为截止"#"前不包括空格的所有字符数量
	cout << "Enter characters; enter # to quit:\n";
	cin >> ch;
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);
		// cin.get()的另一种使用方法,接受一个char变量
	}
	cout << endl << count << "characters read\n";
	// cin.get()会读取包括空格在内的字符
	// 表现为此处输出为截止"#"前包括空格的所有字符数量
	//
	// 还可以通过模拟EOF终止输入
	// 1.cin.fail()只会在读取到EOF时赋值为true
	cout << "Enter characters:\n";
	cin.get(ch);
	while (cin.fail() == false)
		// 新开一行后输入"Ctrl+Z"+"Enter"(EOF)可以终止输入
		// 等价于while (!cin.fail())
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << "characters read\n";
	// 此时会终止读取并输出读取的字符数量
	// 该输入指令仅限Windows系统,其他系统输入指令有所不同
	//
	// 2.直接将cin.get()放置在test-expression是一种更通用的方法
	
	cout << "Enter characters:\n";
	while (cin.get(ch))
		// 同样新起一行读取到EOF时终止读取
		// cin.get(ch)遇到EOF会使输入流失效,进入false状态,使while判定循环条件为假从而终止
	{
		cout << ch;
		++count;
	}
	cout << endl << count << "characters read\n";
	//
	// 3.ch = cin.get()会返回读取字符的ASCII码,可以与EOF进行比较
	int sh;
	cout << "Enter characters:\n";
	while ((sh = cin.get()) != EOF)
		// 同样新起一行读取到"Ctrl+Z"+"Enter"时终止读取
		// EOF的默认int值为-1
	{
		cout.put(char(sh));
		++count;
	}
	cout << endl << count << "characters read\n";
}

void Adv07_NestedLoops_2DArrays()
{
	int maxtemps1[4][5];
	// 创建二维数组格式: typename arrayname[num1][num2]
	// 意为arrayname数组包含num1个元素,每个元素都是一个包含num2个typename元素的数组
	maxtemps1[0];
	// 访问的是maxtemps数组的第一个元素,即一个int数组
	maxtemps1[0][0];
	// 访问的是maxtemps[0]数组的第一个元素,即1个int元素
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 5; ++col)
			cout << maxtemps1[row][col] << "\t";
		cout << endl;
	}
	// 可以通过for循环嵌套来遍历二维数组所有元素并制表
	int maxtemps2[4][5] = 
	{
		{96, 100, 87, 101, 105},
		{96, 98, 91, 107, 104},
		{97, 101, 93, 108, 107},
		{98, 103, 95, 109, 108}
	};
	// 初始化二维数组,类似于初始化数组
	string city = "Forbidden City";
	string cities[5] =
	{
		"Gribble City",
		"Gribbletown",
		"New Gribble",
		"San Gribble",
		"Gribble Vista"
	};
	// 还可以使用string对象的数组,类似二维数组(字符串本身就类似数组)
	// 若不希望字符串被修改,可以在前面加上const
}

void testcode()
{
	//测试函数
	using namespace std;
	char name1[5], name2[5];
	cin.get(name1, 5);
	cout << cin.fail() << '\n';
	cout << name1[0];
}