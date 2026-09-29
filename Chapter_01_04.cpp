/* 执行时弹出警告"该文件包含不能在当前代码页...请将该文件..."属于正常情况,因为文档内中文注释过多 */
/* 修复警告则点击右下角的编码,选择"通过编码重新打开",选择"Unicode(UTF-8带签名)-代码页65001" */
/* 此处推荐一个子体Maple Mono Normal NL NF CN,真的很好看 */

// 以下内容基于Windows平台实现,运行软件为Visual Studio 2026,环境为32位(在上方修改为x86)
// 对于"/**/"注释,仅做拓展说明,无需深入研究

#include "Chapter_01_04.h"

using std::cout;
using std::endl;
// 单独引入std命名空间中的cout和endl，后续使用无需加std::
// 引入在所有函数之前,对后续所有函数都生效

// 第2章
void Cpp_Start()
{
	using namespace std;
	// 引入整个std命名空间,后续使用任意namespace中组件都无需加std::
	// 引入在函数中,只在函数内生效
	// 可能会引起库名称与变量名称冲突
	cout << "Hello, World!";
	// "cout << " 向控制台中输出一段内容
	cout << endl;
	// "cout << endl" 输出一个换行符，让光标移动到下一行
}

void Simon(int n)
// 定义新函数格式:
// "type1 Func(type2 N)
//  {
//	    ...
//  }" 名为Func的函数,接收1个type2类型的参数n,返回1个type1类型的值
	// type1为void时无返回值
{
	cout << "Simon says touch your toes " << n << " times.\n";
	// "<<" 表示数据流向
	// 可以连续拼接多个不同类型的数据
}

int Square(int x)
{
	return x * x;
	// 函数的返回值类型与函数的类型一致
}

void Bas01_Type_cout()
{
	using std::cin;
	int carrots_1;
	// 定义新变量格式:
	// "type var1, var2, ..." 定义名为var1,var2,...的type变量
		// 变量名可以由字母、数字和下划线组成,但不能以数字开头
		// 所有变量必须先定义后使用
	carrots_1 = 25;
	// "=" 赋值符,将右边的值赋给左边的变量
	// 可以连续使用,赋值从右向左进行
		// 例: "a = b = c = 5" 将5赋给c,再将c的值赋给b,最后将b的值赋给a
	// 可以直接在定义变量时赋值
	carrots_1 = carrots_1 - 1;
	// 变量的值可以通过运算符进行修改
	cout << carrots_1 << endl;
	//
	int carrots_2;
	cout << "how many carrots do you have?" << endl;
	cin >> carrots_2;
	// "cin >>" 从键盘获取输入
	cout << "You have "
		<< carrots_2
		<< " carrots."
		<< endl;
	// 可以只使用一个cout将多条语句分放在多行,也可以全部放在一行
	//
	// 使用数学公式需要包含"cmath"头文件
	int x = sqrt(4);
	// "sqrt(N)" 求N的平方根 
	int y = pow(5, 3);
	// "pow(num1, num2)" 求num1的num2次方
	cout << x << " " << y << endl;
}

// 第3章
void Bas02_climits()
{
	// 整型类别: {"short", "int", "long", "long long", "char", "bool"},分别占用2,4,4,8,1,1字节
		// 不同系统占用字节数可能有所不同
		// 查看类型占用字节数格式:
		// "sizeof(N)" 查看变量N的类型占用的字节数
	//
	// 有符号整型格式:
	// "(signed) type" 第1位为符号位,其余位为数值位
		// 例: int共32位,其中第1位为符号位(0负1正),第2~32位为数值位,取值范围为-2^31~2^31-1
	// 无符号整形格式:
	// "unsigned type" 全部位为数值位
		// 例: unsigned int的取值范围为0~2^32-1
	//
	// 符号常量可直接调用不同整型的最大/最小值
	// 使用符号常量需要包含climits头文件
	// 有符号整型符号常量:
	// SHRT_{MAX/MIN}, INT_{MAX/MIN}, LONG_{MAX/MIN}, LLONG_{MAX/MIN}
		// 例: "SHRT_MIN" 对应short类型的最小值,为-2^15 = -32768
	// 无符号整型符号变量:
	// USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
		// 例: "USHRT_MAX" 对应unsigned short类型的最大值,为2^16 - 1 = 65535
	short sam = SHRT_MAX;
	unsigned short sue = sam;
	cout << sam << " " << sue << endl;
	// sam值为32767, sue值为32767
	sam = sam + 1;
	sue = sue + 1;
	cout << sam << " " << sue << endl;
	// sam值为-32768, sue值为32768
	// short的值超过取值范围从而溢出,从最大值回绕到最小值
	const int ZERO = 0;
	// 定义常量格式:
	// "const type Name = value" 定义一个类型为type,值为value的常量Name
		// 常量的值不能被修改,可以在任意位置使用
	// 使用 const 定义常量的好处：
		// 1.多处使用的同一个值,提取为常量后,只需修改定义处即可一键生效
		// 2.保证了变量不可被重新赋值,防止意外的逻辑错误
		// 3.用有意义的变量名替代硬编码,表意清晰
	sam = ZERO;
	sue = ZERO;
	cout << sam << " " << sue << endl;
	// sam值为0, sue值为0
	sam = sam - 1;
	sue = sue - 1;
	cout << sam << " " << sue << endl;
	// sam值为-1, sue值为65535
	// unsigned short的值超过取值范围从而溢出,从最小值回绕到最大值
}

void Bas03_hex_dec_oct()
{
	using namespace std;
	// 16,8,2进制数的开头分别为"0x","0","0b"
	// "decimal"为十进制数,"hexadecimal"为十六进制数,"octal"为八进制数,"binary"为二进制数
	int chest = 42;
	// 42为十进制数
	int waist = 0x42;
	// 0x42为十六进制数,等于十进制数66
	int inseam = 042;
	// 042为八进制数,等于十进制数34
	cout << chest << " " << waist << " " << inseam << endl;
	inseam = waist = chest = 42;
	cout << "chest = " << chest << " (decimal for 42)" << endl;
	cout << hex;
	// 显示整数方式变为十六进制
	cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
	cout << oct;
	// 显示整数方式变为八进制
	cout << "inseam = " << inseam << " (octal for 42)" << endl;
	cout << dec;
	// 显示整数方式变为十进制
	// 没有类似的二进制显示方式
}

void Bas04_char()
{
	// char是用于存储单个字符的整数类型,通常占用1字节
	// char家族包含三种类型: char, signed char, unsigned char
		// signed char通常等价于char,故以下仅讨论char
	// char字符型符号常量:
	// CHAR_BIT, CHAR_MAX, CHAR_MIN, UCHAR_MAX
		// "CHAR_BIT" char类型的位数
	char ch;
	// 定义ch为char字符型变量
	std::cin >> ch;
	// 读取一个字符存入ch,该字符可以是字母,数字,符号
		// ch本质存储的是字符对应的编码值(本书中为ASCII码,后文默认为该编码)
	int i = ch;
	// 将ch存储的ASCII码赋值给int变量i
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Add one to the character code:" << endl;
	ch = ch + 1;
	// 将ch的ASCII码加1
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);
	// "cout.put()"成员函数用于输出单个字符,与"cout << ch"完全等价
		// cout在识别到char类型后,会将存储的编码渲染为对应字符
	cout << endl;
	char sh = '!';
	// 为char类型赋值单个字符使用''引起
	cout << sh << endl;
}

void Bas05_Escape()
{
	using namespace std;
	// 转义字符用于在单个字符或字符串中表示特殊字符或不可打印字符
	// 转义字符以反斜杠"\"开头,后跟一个特定字符
	// 常用的转义字符有:
	// \n 换行符(将光标移动到下一行的开头)
		// 大部分情况下相较endl更常用,更高效
	// \t 制表符(和表格一样前端对齐,相当于一个tab键)
	// \b 退格符(将光标左移一格)
		// 不会删除字符,但后续输出会将其覆盖
	// \r 回车符(会将光标移动到当前行的开头,后字符对前字符进行覆盖)
	// \a 响铃符(触发系统默认的提示音)
	// \\ 反斜杠
	// \' 单引号
	// \" 双引号
	cout << "This is a tab:\tEnd of tab.\n";
	cout << "This is a carriage return:\rEnd of carriage return.\n";
	cout << "This is a backslash: \\\n";
	cout << "This is a single quote: \'\n";
	cout << "This is a double quote: \"";
	cout << "Enter your number:________\b\b\b\b\b\b\b\b";
	//
	cout << "\u4E2d" << '\n';
	// "\u" 通用字符名,后面跟4位16进制数,表示一个Unicode字符
		// 此处会输出对应Unicode编码为4E2d的字符"中"
	bool bo1 = -100;
	bool bo2 = true;
	cout << bo1;
	cout << boolalpha << bo1 << " " << noboolalpha << bo2 << '\n';
	// bool类型用于存储逻辑值
	// bool类型在初始化或接收赋值时,会将非0值转换为true,0值转换为false
	// 默认状态(noboolalpha)下,按整数格式输出: true输出1,false输出0
		// 此处(no)boolalpha用来切换bool值的(数字)真假输出形式
}

void Bas06_float_double()
{
	// 浮点类型: {"float", "double", "long double"},用于表示带小数部分的实数
	// 浮点数支持科学计数法,称为"E表示法",形式为"尾数E指数",意为"尾数×10^指数",适用于极大/极小的数
	float fl_a = +3.5e+7;
	// 此处首尾两个加号都可以省略,等价于3.5E7,"e"等价于"E"
	float fl_b = -3.5E-7;
	// 指数为负表示极小的数,例: 9.11E-31
	cout << fl_a << " " << fl_b << '\n';
	float fl_c = fl_a + 1.0f;
	// 浮点数默认是double类型,可以通过加后缀来指定类型
	// 在浮点数后加"f"/"F"后缀表示float,"l"/"L"表示 long double
		// 整数同样可以加后缀
	cout << fl_c - fl_a << '\n';
	// 各浮点型保证精度的尾数位数:
	// float: 6位; double: 15位; long double: 18位
}

void Bas07_Calculate()
{
	using std::fixed;
	// 算术运算符用来完成基本的算术计算,包括:
	// + 加法
	// - 减法
	// * 乘法
	// / 除法(当两个数均为整数时,执行整数除法,结果向0截断,舍弃小数部分)
	// % 求模(运算的两个数必须都是整型)
	int ca_a = -20;
	int ca_b = 7;
	cout << ca_a % ca_b << " " << (ca_a / ca_b) * ca_b << " " << ca_a << '\n';
	// 若"%"运算存在负数,则结果满足恒等式: (a/b)*b + a%b = a
	// 运算符的优先级: "()" > "*", "/", "%" > "+", "-"
	cout << fixed;
	// 浮点数输出格式切换为定点小数(默认6位小数)
		// "cout << scientific" 浮点数输出格式切换为科学计数法,也需要单独引入std
	cout << "整数除法: 9 / 5 = " << 9 / 5 << '\n';
	// 此处结果为1,整数运算截断了小数部分
	cout << "浮点数除法: 9.0 / 5.0 = " << 9.0 / 5.0 << '\n';
	cout << "浮点数&整数混合除法: 9.0 / 5 = " << 9.0 / 5 << '\n';
	cout << "double浮点型除法(对比): 1e7 / 9 = " << 1e7 / 9 << '\n';
	cout << "float浮点型除法(对比): 1e7f / 9f = " << 1e7f / 9.0f << '\n';
	// 此处结果为1111111.125000, 小数部分是有效位数不够用时产生的正常的舍入误差
}

void Bas08_Type_Trans()
{
	// 类型转换存在显式和隐式两种类型
	// 隐式类型转换: 将一种类型的值赋给另一种类型
	short ca_c = 1000;
	long ca_d;
	ca_d = ca_c;
	// 宽化转换: 小范围类型 -> 大范围类型(short -> long),通常安全,不会丢失数据
	cout << ca_d << '\n';
	ca_d = 98305;
	ca_c = ca_d;
	// 窄化转换: 大范围类型 -> 小范围类型(long -> short),可能丢失数据甚至产生意外结果
	cout << ca_c << '\n';
	/* 窄化转换底层原理:
	   假设:
	       short为小范围类型,long为大范围类型(两种类型为可变任意类型)
	       long N = 98305 -> short, sizeof(short) = small_bit, sizeof(long) = large_bit
	   计算方法:
	       1.取模: 目标类型的最大位数为N_bits = 8 * small_bit, 最大值为N_max = 2 ^ N_bits
				   将变量值对N_max求模: temp = N % N_max
		   2.符号判定(补码规则): 如果目标类型是有符号类型,且 temp >= 2^(N_bits - 1),
								 则short N = temp - N_max;
								 否则, short N = temp */
	long thron = 50000;
	cout << short(thron) << endl;
	cout << static_cast<short>(thron) << endl;
	// 显式类型转换: 强制转换,将变量转换为另一种类型
		// 强制转换不会修改变量本身,而是创建一个新的指定类型的值
	// 2种强制转换格式:
		// "typename(value)" -- C风格 
		// "static_cast<typename>(value)" -- C++风格(更常用)
	cout << thron << endl;
	auto ca_e = 3.5;
	// auto类型允许程序自行推断变量的类型
		// 此处ca_e为double类型,值为3.5f时才是float类型
	// auto类型需关注值的后缀,避免出现精度等问题
	
}

// 第4章
void Bas09_array()
{
	// 数组是一种数据格式,能存储多个同类型的元素
	// 数组初始化通用格式: 
	// "type Name[size]" 名为Name的数组能存储size个type类型元素
		// size必须是确定的常量表达式,不能是运行时才确定的变量
	int array_exa[2];
	// 数组的类型是"type数组",并非"数组"
		// 此处array_exa的类型是"int数组"
	// 局部数组未初始化,元素值是未定义的,切勿直接使用
	array_exa[0] = 5;
	array_exa[1] = 9;
	cout << array_exa[0];
	// 为数组内元素赋值
	int arr_1[4] = {10, 4};
	// 按顺序赋值,未显式赋值的元素会被隐式初始化为0
		// 只有在定义数组时才能如此赋值,不能像变量"a = b"那样让数组互相赋值
	double arr_2[3] {1.2, 1.4, 2.5};
	// C++初始化数组可以省略"="
	int arr_3[7] {};
	// 大括号内为空时默认所有元素设置为0
		// 此处等价于"int arr_3[7] = {0}", 第一个元素显式赋0,其余元素隐式赋0
	char arr_4[4] = {'h', '!', 115, '\a'};
	// 数组初始化禁止缩窄转换
		// 方括号内数据不允许非字符型,非整型,超过char数值范围
	char arr_5[] = {'q', '&', 'f'};
	// 方括号内不填入数字时,编译器会根据列表自动计算数组内有多少元素
}

void Bas10_cstring()
{
	// 字符串是连续字节中的一系列字符,可以存储在char数组中
	// 处理字符串有两种方法,此处介绍C-style string(C-风格字符串)
	char dog[4] = { 's', 'e', 'f', 'd' };
	// 这是普通的char数组,并非字符串
	char cat[4] = {'d', 'f', ' ', '\0'};
	// 这是C-style string
	// C-style string必须以空字符结尾,写作'\0',ASCII编码为0
	char bird[11] = "Mr. Cheeps";
	// 可以直接让char数组等于字符串,""引起的字符串隐式地包含'\0'
	char chr = 'S';
	// ''和""不能互换
	// 'S'为字符常量,对应ASCII码的83
	// "S"为字符串常量,表示的是'S'和'\0'组成的字符串
	cout << "I want eat cakes\n";
	cout << "I want eat"" cakes\n";
	cout << "I want eat" " cakes\n";
	cout << "I want eat"	" cakes\n";
	cout << "I want eat"
		" cakes\n";
	// C++允许拼接相邻的字符串
	// 两个字符串间可以贴在一起,也可以通过空白(空格,制表符(Tab键),换行符)分隔
	//
	// 介绍一些C-style string常用的函数
		// 使用该类函数必须包含cstring头文件
	char Mzrui[30] = "Hello,I am Mzrui!";
	Mzrui[14] = '\0';
	cout << strlen(Mzrui) << '\n';
	// "strlen(Name)" 计算字符串的长度(不包含结尾的'\0')
	// '\0'会使字符串的读取在此处终止
	char chcpy[5] {};
	strncpy(chcpy, Mzrui, 5);
	chcpy[4] = '\0';
	cout << chcpy << '\n';
	// "strncpy(char1, char2, N)" 让char1最多复制char2的前N个字符
		// 该复制只会影响char1的前N个字符,与后续字符无关
	// 若N >= strlen(char1),则需手动将最后一个字符替换为'\0',否则会输出乱码
	strncat(Mzrui, "TXTTUT", 3);
	cout << Mzrui << '\n';
	// "strncat(char1, char2, N)" 在char1的末尾拼接char2的前N个字符
	// 若char1还有空余位置,strncat会自动在末尾补上'\0',否则还是需要手动将最后一个字符替换为'\0'
	cout << strncmp(Mzrui, "Hellh", 5);
	// "strncmp(char1, char2, N)" 比较char1和char2前n个字符中第一个不同的字符的ASCII编码大小
}

void Bas11_cin_Enter()
	/* 此处代码请自行分块复制到测试函数中运行 */
{
	using std::cin;
	// 使用"cin >>"读取字符串存在着一些隐患
	// "cin >>"会跳过开头的空白字符,遇到第一个非空白字符开始读取,在下一个空白字符前停止读取
	char name1[20], name2[20];
	cout << "enter one name: \n";
	cin >> name1;
	// 此处输入"Alex Herb"
	cout << "enter another name: \n";
	cin >> name2;
	cout << name1 << name2 << '\n';
	// name2的输入窗口看起来被直接跳过了,但name2依旧被赋予了字符串
		// 对name1,cin读取了"Alex",遇到空格停止读取,此时缓冲区还留有" Herb"
		// 对name2,cin发现缓冲区内还有剩余的字符,跳过开头的字符,读取了"Herb"
	char ch[5];
	cin >> ch;
	// 此处输入"abcdefg"
	cout << ch;
	// 数组只能存储键入字符串前size - 1个字符 + '\0'
	//
	char name3[10];
	cin.getline(name3, 10);
	// getline函数格式: 
	// "cin.getline(Name,size)" 读取一行字符串,存入名为Name,大小为size的char数组中
	// getline函数使用换行符(\n或回车)确定字符串结束位置,并清除末尾的'\n'
	cin.get(name1, 20);
	cin.get(name2, 20);
	// get函数格式: 
	// "cin.get(Name,size)" 读取一行字符串,存入名为Name,大小为size的char数组中
	// get类似getline读取一行,但不清除末尾的'\n'
		// 此处第二个cin.get会读取到第一次遗留下的'\n',于是认为输入已经结束,表现为只输入了一次
	//
	// cin可以进行链式调用
	cin.get(name3, 10).get();
	// 等价于分开调用"cin.get(name3,10)"和"cin.get()"
	cin.getline(name1, 20).getline(name2, 20);
	// 等价于分开两次调用getline(Name, size)
	// 
	// cin在使用时会出现设置failbit的情况,后续cin读取到failbit会失效: 
		// 1."cin.get(Name, size)"读取到换行符
		// 2."cin.getline(Name, size)"读取超过char数组size的字符串
		// 3."cin >>"输入类型不匹配
	//
	// 解决failbit方案: 
		// 1."cin.get()"可以提取并丢掉缓冲区的一个字符(通常是'\n')
	cin.get(name1, 20);
	cin.get();
	cin.get(name2, 20);
		// 2.
	cin.clear();
	cin.ignore(10000, '\n');
	cin.get(name2, 20);
	cout << name1 << " " << name2 << endl;
	// cin.clear()可以清除设置的失效位
	// cin.clear()无法清除字符串过长时残留的字符,之后使用cin会继续读取之前未读取完的字符
	// cin.ignore()是cin.get()的完全上位替代
	// cin.ignore(num, 'char')意为删除缓冲区最多num个字符,遇到ch字符则清除并停止
	int num1;
	(cin >> num1).ignore(100, '\n');
	// cin >>输入数字后,需要使用cin.ignore()/cin.get()清除末尾的\n
	// 等价于分开使用cin >> num1和cin.ignore()
}

void Bas12_string()
{
	using namespace std;
	// 此处介绍处理字符串的第二种方法:string类
	// 需要使用using namespace std或using std::string来引用string类
	char arr[20];
	string str1;
	// 无需同char数组一样声明数组长度
	string str2 = "apple";
	cout << "Enter a word: ";
	cin >> str1;
	cout << "Here are some words: " << str1 << " " << str2 << endl;
	cout << "The third letter ib " << str2 << " is " << str2[2] << endl;
	// string对象与char数组的使用方式基本相同
	// string对象可以声明为简单变量,并且不受数组长度限制
	string str3 {"I am a test sentence"};
	// string对象也可以同数组一样使用大括号初始化
	str1 = str2;
	cout << str1 << " " << str2 << endl;
	// string对象可以赋值给另一个string对象
	string str4 = str1 + str2;
	str1 += str2;
	cout << str4 << " " << str1 << endl;
	// string类可以通过"+"或"+="来合并string对象
	int len1 = str2.size();
	// size函数可以确定string对象的长度
	string str;
	getline(cin, str);
	cout << str << endl;
	// 将1行输入读取到string对象中
	// 此处的getline并非cin的类方法
}

void Bas13_Structure()
{
	using std::cin;
	// 结构可以同时存储多种数据类型
	// 结构可以选择放在main函数前或函数内部
	// 前者可用于所有后续函数,后者只能用于所属函数
	struct inflatable
		// 定义结构,struct为"结构"类型的关键字,"inflatable"为该类型的名称
	{
		char name[20];
		float volume;
		double price;
	};
	// 大括号内部为结构的成员
	struct inflatable hat;
	inflatable mainframe;
	// 声明struct变量时可以省略结构名称前的关键字
	hat.volume;
	// 声明的变量可以访问结构内的成员
	inflatable guest = {
		"Glorious Gloria",
		1.88,
		29.39
	};
	inflatable duck = {"Daphne", 0.12, 9.98};
	inflatable cayon {"rumpo", 0.13, 0.22};
	// 初始化结构使用"={}"或"{}",值列表使用","分隔
	// 值列表可以全部放在同一行
	inflatable mayor {};
	// 大括号内为空则成员都被设置为0,char数组的每个字符都被设置为0
	// 结构内成员的值不允许缩窄转换
	struct infe {std::string name;};
	// 结构内成员也可以指定为string对象
	mayor = duck;
	cout << mayor.name << " " << mayor.volume << endl;
	// 结构中的成员可以被赋予另一个结构中成员的值
	struct perks {
		int key_number;
		char car[12];
	} mr_smith, mr_jones = {7, "packard"};
	// 在定义结构体时可以顺便创建和初始化变量
	inflatable gifts[100];
	cin >> gifts[0].volume;
	cout << gifts[99].price << endl;
	// 可以创建元素为结构的数组
	inflatable guests[2] =
	{
		{"bambi", 0.5, 21.99},
		{"Godway", 2000, 561.80}
	};
	// 可以为每一个结构赋值得到完全初始化的结构数组
	union one4all
	{
		int int_val;
		double double_val;
		float float_val;
	};
	// 共用体(union)是一种数据格式,其可以存储多种数据,但同时只能存储1种数据
	struct knife
	{
		int typ;
		union id
		{
			long id_num;
			char id_char[20];
		} id_val;
	};
	knife sts;
	cin >> sts.typ;
	if (sts.typ == 1)
		cin >> sts.id_val.id_num;
	else
		cin >> sts.id_val.id_char;
	// union常用于节省内存
	/* 此处的if-else逻辑后文会详细讲解,此处无需过多注意 */
}

void Bas14_Enumeration()
{
	// enum可以定义一种创建符号常量的新类型
	enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
	// 这种新类型称为枚举,spectrum为枚举的名称,red,orange...为枚举的符号常量
	spectrum band;
	band = blue;
	// 枚举变量的值只能为定义枚举时的符号常量
	// 枚举只定义了"=",无法使用其他运算符
	int color = band;
	// 枚举的符号常量与从0开始的整数(包括0)一一对应
	band = spectrum(3);
	// 可以通过强制转换将int值赋给枚举变量
	// 不能直接将int主动赋值给枚举变量
	enum bits {zero = 0, one = 1, second = 100, third};
	// 可以对对枚举的符号常量进行赋值,未赋值的枚举量默认比前一位大1
	bits myflag;
	myflag = bits(6);
	// 这种情况是被允许的,访问值位于枚举量的取值范围内,输出结果即为访问值6
}
void Bas15_Pointer()
{
	// 指针是一个变量,存储的不是值本身,而是值的地址
	int donuts = 6;
	double cups = 4.5;
	cout << "donuts value = " << donuts << " and donuts address = " << &donuts << endl;
	cout << "cups value = " << cups << " and cups address = " << &cups << endl;
	// "&"为地址运算符,用来查询数据对象的地址,并使用hex来显示地址
	// 一般情况下此处两个变量的地址相差4,因为先存储int,int占4字节
	int updates = 6;
	int* p_updates;
	p_updates = &updates;
	cout << updates << " " << *p_updates << " " << &updates << endl;
	// "*"为解除引用运算符,它可以解除"&"的引用,得到地址处存储的值
	// 可以理解为等号两边的"*"和"&"是可以互相抵消的
	/* 若是发现输出地址前有很长一串0,请在上方将"x64"修改为"x86" */
	double* p1, p2;
	// 此处创建了指针p1和double变量p2
	// 对每个指针变量名,都需要使用1个*
	int higgens = 5;
	int* pt = &higgens;
	// 可以通过声明语句初始化指针,此处将pt初始化为&higgens
	// 使用*之前一定要将指针初始化为一个确定合法的地址,否则可能会碰到很坏的情况
	int* pt1;
	pt1 = (int*)0xB8000000;
	// 想要直接给指针赋予地址需要通过强制转换将类似地址的整数转化为地址
	int* pn = new int;
	// new运算符可以在运行时为某种type的值分配未命名的内存,并使用指针访问该值
	// 使用new为数据对象获得内存的格式:"typename* pointer_name = new typename"
	// 此处pn指向的是一个"数据对象",说的是为数据项分配的内存块
	double* pd = new double;
	*pd = 10000001.0;
	cout << sizeof(pd) << " " << sizeof(*pd) << endl;
	// 在32位系统下,指针的大小永远是4字节(32位/8)
	delete pd;
	// delete可以删除使用new分配的内存,不能删除普通变量使用的内存
	// delete删除的是内存块而不是指针
	// delete只能删除同一个内存块1次
	int* ps = new int;
	int* pa = ps;
	delete pa;
	// delete只需要指向该内存的地址,并不需要指针完全相同
	//
	int* ppt = new int;
	short* pps = new short[500];
	delete ppt;
	delete[] pps;
	// new可以创建动态数组,这样的数组可以包含指定数量的指定类型元素
	// 创建动态数组格式为"typename* pointername = new typename[arraysize]"
	// 删除动态数组占用的内存需要使用"delete[]"
	ppt = nullptr;
	pps = nullptr;
	// 当一个指针被设置为空指针(nullptr),此时对其多次使用delete是安全的
	// 被删除内存块的指针不是空指针,因为其还保留着地址
	// 动态数组不能使用sizeof()来确定包含的字节数
	double* p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[0] is  " << p3[0] << endl;
	// 若是使用new创建动态数组,可以将指针当做数组名来使用
	p3 = p3 + 1;
	cout << "now p3[0] is " << *p3 << " now p3[1] is " << p3[1] << endl;
	// 指针可以作为数组名,也可以看做指在动态数组元素下的手指
	// 默认情况下,*pointername指数组第1个元素的地址,同时pointername[0]从此位置读取元素
	// 可以对*pointername进行+num/-num的操作,意为将手指向前/向后移动n个元素
	delete p3;
}

void Bas16_Pointer_Arithmetic()
{
	using std::cin;
	// 对地址进行+-运算会根据地址对应的数据对象类型的字节数进行运算
	double wages[3] = {10000.0, 20000.0, 30000.0};
	short stacks[3] = {3, 2, 1};
	double* pw = wages;
	// 此处数组名可以转换成指向第1个元素的指针,如wages在此处与&wages[0]等价
	short* ps = &stacks[0];
	cout << "pw = " << pw << " *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "add 1 to the ps pointer:\n";
	cout << "pw = " << pw << " *pw = " << *pw << "\n\n";
	// 此处为double数组,double浮点型对应8字节,所以指针值增加8
	cout << "ps = " << ps << " *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "add 1 to the ps pointer:\n";
	cout << "ps = " << ps << " *ps = " << *ps << "\n\n";
	// 此处为short数组,short整型对应2字节,所以指针值增加2
	cout << "stacks[0] = " << stacks[0] << " stacks[1] = " << stacks[1] << endl;
	cout << "*stacks = " << *stacks << " *(stacks + 1) = " << *(stacks + 1) << endl;
	// 此处*(arrayname + num) = pointername[num],都代表从指针指向的元素开始向后数num个元素
	cout << "size of wages array is " << sizeof(wages);
	// 此处可以对数组使用sizeof是因为wages为明确元素的静态数组
	cout << "size of pw array is " << sizeof(pw);
	// 
	short tell[10];
	cout << tell << " " << &tell << endl;
	cout << tell + 1 << " " << &tell + 1 << endl;
	// tell表示的是数组内第1个元素的地址,&tell表示的是整个数组的地址
	// 所以此处tell + 1会使地址增加2字节,&tell + 1会使地址增加20字节
	char flower[10] = "rose";
	cout << flower;
	// 在多数表达式中,char数组名,char指针和""引起的字符串都常被解释为字符串第一个字符的地址
	// cout会从该地址开始打印,直到遇见空字符
	const char* bird = "Wren";
	// 这样声明指针变量时需要使用const,表示该字符串不可被修改
	cout << (void*)bird;
	// 在使用cout直接打印char*时,会直接输出指针地址对应的字符串;打印int*,非char数组名等非字符指针时,会输出指针对应的地址
	// 想要使用cout打印char*对应的地址,需要使用(void*)pointername
	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};
	inflatable* pl = new inflatable;
	// 可以通过new为指针赋予足以存储结构的内存的地址
	cin.getline(pl->name, 20);
	cin >> (*pl).volume;
	cin >> pl->price;
	cout << pl->name << " " << (*pl).volume << " " << (*pl).price << endl;
	delete pl;
	// 上述是2种(第3个与第1种同理)访问结构成员的指针表示法
}

void Bas17_Type_Combination()
{
	// 数组,结构,指针可以以各种方式来结合使用
	struct antatctica_years_end
	{
		int year;
	} s01, s02, s03;
	s01.year = 1998;
	antatctica_years_end* pa = &s02;
	// 此处pa是指向结构变量s02的地址
	pa->year = 1999;
	antatctica_years_end trio[3];
	// 此处定义了包含三个结构变量的数组
	trio[0].year = 2003;
	cout << trio->year << endl;
	// 数组名字默认为指向第一个元素的指针,此处输出即为trio[0].year
	const antatctica_years_end* arp[3] = {&s01, &s02, &s03};
	// 此处定义了包含3个结构地址的数组
	cout << arp[1]->year << endl;
	const antatctica_years_end** ppa = arp;
	// 此处这样理解:arp是一个指向指针的指针,是一个2级指针,相当于&(&s01)(这么写是不对的,但可以这么理解)
	// ppa=arp也是一层2级指针,前面每加一个*,就相当于去掉一个&
	// 也就是*ppa=&s01,**ppa=s01
	auto ppb = arp;
	// 此处的auto是C++独特的关键字,根据等号右边的类型来定义等号左边的类型
	cout << (*ppa)->year << endl;
	cout << (*(ppb + 1))->year << endl;
	// 此处让等于arp的ppb指向了下一个元素,也就是指向&s02的指针
	// 
	antatctica_years_end* pb = new antatctica_years_end[5];
	// 可以通过new来创建动态结构体数组
}

void Bas18_vector_array()
{
	using std::vector;
	using std::array;
	// 此处仅对vector和array进行介绍
	// 模版类vector类包含在std中,需要using声明
	// 声明vector类的格式:"vector<typename> vectorname(n_elem)"
	// 意思是创建一个名为vectorname的vector对象,可以存储n_elem个类型为typename的元素
	// n_elem可以是整型常量和整型变量
	// vector对象会在插入/添加值时自动调整长度,n_elem可以被设为0
	vector<double> a1{4};
	// 模板类array类包含在std中,需要using声明
	// 声明array类的格式:"array<typename, n_elem> arrayname"
	// 意思是创建一个名为arrayname的array对象,可以存储n_elem个类型为typename的元素
	// n_elem只能是整型常量
	array<double, 4> a2 = {3.14, 2.72, 1.62, 1.41};
	double a3[4] = {1.2, 2.4, 3.6, 4.8};
	a1[0] = 5.0;
	a2[0] = 5.0;
	cout << a1[0] << " " << a2[0] << endl;
}
