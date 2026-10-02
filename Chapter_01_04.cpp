/* 执行时弹出警告"该文件包含不能在当前代码页...请将该文件..."属于正常情况,因为文档内中文注释过多 */
/* 修复警告则点击右下角的编码,选择"通过编码重新打开",选择"Unicode(UTF-8带签名)-代码页65001" */
/* 此处推荐一个子体Maple Mono Normal NL NF CN,真的很好看 */

// 以下内容基于Windows平台实现,运行软件为Visual Studio 2026,环境为32位(在上方修改为x86)
// 对于"/* ... */"注释,仅做拓展说明,无需深入研究

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
// "type1 func_Name(type2 N)
//  {
//	    ...
//  }" 名为func_Name的函数,接收1个type2类型的参数n,返回1个type1类型的值
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
	// "type var_Name1, var_Name2, ..." 定义名为var_Name1,var_Name2,...的type变量
		// 变量名可以由字母、数字和下划线组成,但不能以数字开头
		// 所有变量必须先定义后使用

	carrots_1 = 25;
	// "=" 赋值符,将右边的值赋给左边的变量
	// 可以连续使用,赋值从右向左进行
		// 例: "a = b = c = 5" 将5赋给c,再将c的值赋给b,最后将b的值赋给a
	// 可以直接在定义变量时赋值

	carrots_1 = carrots_1 - 1;
	cout << carrots_1 << endl;
	// 变量的值可以通过运算符进行修改

	int carrots_2;
	cout << "how many carrots do you have?" << endl;
	cin >> carrots_2;
	// "cin >>" 从键盘获取输入
	cout << "You have "
		<< carrots_2
		<< " carrots."
		<< endl;
	// 可以只使用一个cout将多条语句分放在多行,也可以全部放在一行

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
		// "sizeof(var_Name)" 查看变量var_Name的类型占用的字节数

	// 有符号整型格式:
	// "(signed) type" 第1位为符号位,其余位为数值位
		// 例: int共32位,其中第1位为符号位(0负1正),第2~32位为数值位,取值范围为-2^31~2^31-1
	// 无符号整形格式:
	// "unsigned type" 全部位为数值位
		// 例: unsigned int的取值范围为0~2^32-1

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
	// "const type con_Name = value" 定义一个类型为type,值为value的常量con_Name
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
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;
	// char类型运算时时先隐式转为int相加/减，再隐式转回char存储
		// 此处即为ch的ASCII码 + 1后的对应字符

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
	// 超过这个精度的运算将不能保证精确
}

void Bas07_Calculate()
{
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

	cout << std::fixed;
	// 浮点数输出格式切换为定点小数(默认6位小数)
		// "cout << std::scientific" 浮点数输出格式切换为科学计数法

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
	       sizeof(short) = small_bit, sizeof(long) = large_bit
	   目标:
		   long N = 98305 -> short(N) = ?
	   计算方法:
	       1.取模: 目标类型的最大位数为N_bits = 8 * small_bit, 最大值为N_max = 2 ^ N_bits
				   将变量值对N_max求模: temp = N % N_max
		   2.符号判定(补码规则): 如果目标类型是有符号类型,且 temp >= 2^(N_bits - 1),
								 则short(N) = temp - N_max;
								 否则, short(N) = temp
	*/

	long thron = 50000;
	cout << thron << '\n';
	cout << short(thron) << '\n';
	cout << static_cast<short>(thron) << '\n';
	// 显式类型转换: 强制转换,将变量转换为另一种类型
		// 强制转换不会修改变量本身,而是创建一个新的指定类型的值
	// 2种强制转换格式:
		// "type(var_Name)" -- C风格 
		// "static_cast<type>(var_Name)" -- C++风格(更常用)

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
	// "type array_Name[size]" 名为array_Name的数组最多能存储size个type类型元素
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
	// 所有类型数组在初始化时都禁止缩窄转换
		// 此处char数组方括号内数据不允许出现非字符型或非整型,值不能超过char数值范围

	char arr_5[] = {'q', '&', 'f'};
	// 方括号内不填入数字时,编译器会根据列表自动计算数组内有多少元素
}

void Bas10_cstring()
{
	// 字符串是连续字节中的一系列字符,可以存储在char数组中
	// 处理字符串有两种方法,此处介绍第一种方法: C-style string(C-风格字符串)

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

	// 介绍一些C-style string常用的函数,使用该类函数必须包含cstring头文件:
	//
	// 1. "strlen(str)" 计算字符串的长度(不包含结尾的'\0')
		// '\0'会使字符串的读取在此处终止
	char Mzrui[30] = "Hello,I am Mzrui!";
	Mzrui[14] = '\0';
	cout << strlen(Mzrui) << '\n';

	// 2. "strncpy(str1, str2, N)" 让str1最多复制str2的前N个字符
		// 该复制只会影响str1的前N个字符,与后续字符无关
		// 若N >= strlen(str1),则需手动将最后一个字符替换为'\0',否则会输出乱码
	char chcpy[5] {};
	strncpy(chcpy, Mzrui, 5);
	chcpy[4] = '\0';
	cout << chcpy << '\n';

	// 3. "strncat(str1, str2, N)" 在str1的末尾拼接str2的前N个字符
		// 若str1还有空余位置,strncat会自动在末尾补上'\0',否则还是需要手动将最后一个字符替换为'\0'
	strncat(Mzrui, "TXTTUT", 3);
	cout << Mzrui << '\n';

	// 4. "strncmp(str1, str2, N)" 比较str1和str2前n个字符中第一个不同的字符的ASCII编码大小
	cout << strncmp(Mzrui, "Hellh", 5);
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

	char name3[10];
	cin.getline(name3, 10);
	// getline函数格式: 
	// "cin.getline(char_Name,size)" 读取一行字符串,存入名为char_Name,大小为size的char数组中
	// getline函数使用换行符(\n或回车)确定字符串结束位置,并清除末尾的'\n'

	cin.get(name1, 20);
	cin.get(name2, 20);
	// get函数格式: 
	// "cin.get(char_Name,size)" 读取一行字符串,存入名为char_Name,大小为size的char数组中
	// get类似getline读取一行,但不清除末尾的'\n'
		// 此处第二个cin.get(...)会读取到第一次遗留下的'\n',于是认为输入已经结束,表现为只输入了一次

	// cin可以进行链式调用
	cin.get(name3, 10).get();
	// 等价于分开调用"cin.get(...)"和"cin.get()"
	cin.getline(name1, 20).getline(name2, 20);
	// 等价于分开两次调用"getline(...)"
	int num1;
	(cin >> num1).ignore(100, '\n');
	// 等价于分开使用"cin >> num1"和"cin.ignore()"

	// cin在使用时会出现设置failbit的情况,后续cin读取到failbit会失效: 
	// 
	// 1."cin.get(char_Name, size)"读取到换行符
	// 2."cin.getline(char_Name, size)"读取超过char数组size的字符串

	// 解决failbit方案: 
	//
	// 1. "cin.get()" 提取并丢掉缓冲区的一个字符(通常是'\n')
		// 此时缓冲区内没有'\n',"cin.get(char_Name, size)"不会再设置failbit
	cin.get(name1, 20);
	cin.get();
	cin.get(name2, 20);

	// 2. "cin.clear()" 清除设置的失效位
		// "cin.clear()"无法清除字符串过长时残留的字符,之后使用cin会继续读取之前未读取完的字符
	cin.clear();

	// 3. "cin.ignore(N, 'ch')" 删除缓冲区最多N个字符,遇到'ch'字符则清除并停止
		// "cin.ignore(N, 'ch')"是"cin.get()"的完全上位替代
	cin.ignore(10000, '\n');
}

void Bas12_string()
{
	using namespace std;
	// 此处介绍处理字符串的第二种方法: std::string类

	char arr[20];
	string str1;
	// 无需同char数组一样声明string对象长度

	string str2 = "apple";
	cout << "Enter a word: ";
	cin >> str1;
	cout << "Here are some words: " << str1 << " " << str2 << endl;
	cout << "The third letter in " << str2 << " is " << str2[2] << endl;
	// string对象支持类似数组的索引访问
	// string对象可以声明为简单变量,并且不受数组长度限制

	string str3 {"I am a test sentence"};
	// string对象可以使用大括号初始化

	str1 = str2;
	cout << str1 << " " << str2 << endl;
	// string对象之间可以互相赋值
	string str4 = str1 + str2;
	str1 += str2;
	cout << str4 << " " << str1 << endl;
	// string类可以通过"+"或"+="进行拼接

	int len1 = str2.size();
	// "str.size()" 获取string对象str的长度

	string str5;
	getline(cin, str5);
	cout << str5 << endl;
	// "getline(cin, str)" 读取整行输入到string对象str中
		// 此处的"getline(...)"是std命名空间下的独立函数，并非cin的成员方法
}

void Bas13_Structure()
{
	using std::cin;
	// 结构体可以同时存储多种数据类型,可以选择放在main函数前或函数内部
	// 前者可用于所有后续函数,后者只能用于所属函数

	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};
	// 定义结构体,struct为"结构"类型的关键字,"inflatable"为该结构体的名称
	// 大括号内部为结构的成员

	struct inflatable hat;
	inflatable mainframe;
	// 声明结构体变量时,可以省略结构名称前的关键字"struct"
	hat.volume;
	// struct变量可以通过"."访问结构内的成员

	inflatable guest = {
		"Glorious Gloria",
		1.88,
		29.39
	};
	inflatable duck = {"Daphne", 0.12, 9.98};
	inflatable cayon {"rumpo", 0.13, 0.22};
	// 初始化结构使用"= {}"或"{}",值列表使用","分隔
	// 值列表可以分多行写,也可以全部放在同一行
	inflatable mayor {};
	// 大括号内为空则成员都被设置为0,char数组的每个字符都被设置为0
	// 结构内成员的值不允许缩窄转换
	struct infe {std::string name;};
	// 结构内成员也可以指定为string对象

	mayor = duck;
	cout << mayor.name << " " << mayor.volume << endl;
	// 同类型的结构体变量之间可以直接相互赋值(对应成员会逐一拷贝)

	struct perks {
		int key_number;
		char car[12];
	} mr_smith, mr_jones = {7, "packard"};
	// 在定义结构体时可以顺便创建和初始化变量

	inflatable gifts[100];
	cin >> gifts[0].volume;
	cout << gifts[99].price << endl;
	// 可以创建元素为结构体的数组
	inflatable guests[2] =
	{
		{"bambi", 0.5, 21.99},
		{"Godway", 2000, 561.80}
	};
	// 可以用大括号嵌套的方式,为结构体数组的每个元素赋初值

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
		// "id_num"和"id_char"同一时间只会用到其中一个(由typ决定)
		// 所以它们共享同一块内存空间,从而避免了同时分配两块内存造成的浪费 
	/* 此处的if-else逻辑后文会详细讲解,此处无需过多注意 */
}

void Bas14_Enumeration()
{
	// "enum" 定义一种创建符号常量的新类型"枚举"

	enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
	// spectrum为枚举的名称,red,orange...为枚举的符号常量

	spectrum band;
	band = orange;
	// 枚举变量的值只能为定义枚举时的符号常量
	// 枚举不能进行算术等运算,只能使用"="

	int color = band;
	// 枚举的符号常量与从0开始的整数(包括0)一一对应
		// 此处color存储值为1

	band = spectrum(3);
	// 可以通过显式类型转换将int值赋给枚举变量
	// 但不支持直接将int隐式赋值给枚举变量(例如直接写band = 3是错误的)
		// 若执行"cout << band",输出的是整数3,而不是字符串"green"

	enum bits {zero = 0, one = 1, second = 100, third};
	// 可以对对枚举的符号常量进行赋值,未赋值的枚举量默认比前一位大1

	bits myflag;
	myflag = bits(6);
	cout << myflag << '\n';
	// 这种情况是被允许的,访问值位于枚举量的取值范围内
		// 此处输出结果为6,但它没有对应的符号常量名
}
void Bas15_Pointer()
{
	// 指针是一个变量,存储的不是数据本身,而是数据在内存中的地址

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
	// 可以通俗理解为:
		// 1.对于"&*"和"*&",两个符号紧挨在一起时会互相抵消,相当于无事发生
		// 2.将"*指针"看成一个整体,那么这个整体就等于"="另一侧去掉"&"后剩余的部分
		// 3.将"&值"看成一个整体,那么这个整体就等于"="另一侧去掉"*"后剩余的部分

	double* p1, p2;
	// "*"只对紧随其后的变量生效,想要创建多个指针,需要在每个变量名前添加"*"
		// 此处创建了double指针p1和double变量p2
		// 若想创建2个指针需要改为"double *p1, *p2;"

	int higgens = 5;
	int* pt = &higgens;
	// 可以通过声明语句初始化指针
		// 此处将pt初始化为&higgens
	// 使用"*"之前一定要将指针初始化为一个确定且合法的地址

	int* pt1;
	pt1 = (int*)0xB8000000;
	// 想要直接给指针赋予具体的内存地址,需要将该16进制整数显式强制转换为对应的指针类型

	int* pn = new int;
	// new运算符可以在运行时为某种type的值分配未命名的内存,并使用指针访问该值
	// 使用new为数据对象获得内存的格式: 
	// "type* poi_Name = new type" 为单个数据对象动态分配了一块内存,并将该内存的起始地址返回给指针poi_Name
		// 此处pn指向的是一个"数据对象",说的是为数据项分配的内存块
	double* pd = new double;
	*pd = 10000001.0;
	cout << sizeof(pd) << " " << sizeof(*pd) << endl;
	// 在32位系统(x86)下,指针的大小永远是4字节(32位/8)
		// 在64位系统(x64)下为8字节

	delete pd;
	// delete可以释放使用new分配的内存,不能释放普通变量声明的内存
	// delete释放的是内存块而不是指针
	// delete只能释放同一个内存块1次
	int* ps = new int;
	int* pa = ps;
	delete pa;
	// delete只需要该内存块的地址即可释放,并不需要指针完全相同

	int* ppt = new int;
	short* pps = new short[500];
	delete ppt;
	delete[] pps;
	// new可以创建动态数组,这样的数组可以包含指定数量的指定类型元素
	// 创建动态数组格式: 
	// "type* poi_Name = new type[size]" 创建包含size个元素的动态数组,并把数组首元素的地址返回给指针poi_Name
	// 删除动态数组占用的内存需要使用"delete[]"
	ppt = nullptr;
	pps = nullptr;
	// 当一个指针被设置为空指针(nullptr),此时对其多次使用delete是安全的
	// 被删除内存块的指针不是空指针,因为其还保留着原来的地址
	// 动态数组使用"sizeof()"只能得到指针本身的大小，无法确定整个数组包含的字节数

	double* p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	double* temp = p3;
	cout << "p3[0] is  " << p3[0] << endl;
	// 若是使用new创建动态数组,可以将指针当做数组名来使用
	p3 = p3 + 1;
	cout << "now p3[0] is " << *p3 << " now p3[1] is " << p3[1] << endl;
	// 指针可以作为数组名,也可以看做指在动态数组元素下的"手指"
	// 可以对poi_Name进行+N/-N的操作,意为将手指向前/向后移动N个元素
	// 指针poi_Name指向元素的地址即是"手指"的位置,这个位置就是poi_Name[0]所表示的元素
		// 执行"p3 = p3 + 1"后,此时指针p3指向地址处的元素,也就是此时的p3[0]为0.5
	delete[] temp;
	// 执行"p3 = p3 + 1"后,p3不再指向原数组的首地址,此时不能直接"delete[] p3"
	// 正确的做法是在移动前用另一个指针保存首地址,释放时delete[] 原始指针
}

void Bas16_Pointer_Arithmetic()
{
	using std::cin;
	// 对地址进行加减运算时,会根据地址指向的数据对象类型的字节数进行偏移

	double wages[3] = {10000.0, 20000.0, 30000.0};
	short stacks[3] = {3, 2, 1};
	double* pw = wages;
	short* ps = &stacks[0];
	// 在大多数表达式中,数组名会被隐式转换为指向数组首元素的指针
		// 如wages在此处与&wages[0]等价

	cout << "pw = " << pw << " *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "add 1 to the pw pointer:\n";
	cout << "pw = " << pw << " *pw = " << *pw << "\n\n";
	// 此处为double数组,double浮点型对应8字节,所以指针值增加8

	cout << "ps = " << ps << " *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "add 1 to the ps pointer:\n";
	cout << "ps = " << ps << " *ps = " << *ps << "\n\n";
	// 此处为short数组,short整型对应2字节,所以指针值增加2

	cout << "stacks[0] = " << stacks[0] << " stacks[1] = " << stacks[1] << endl;
	cout << "*stacks = " << *stacks << " *(stacks + 1) = " << *(stacks + 1) << endl;
	// 此处*(array_Name + N) = Name[N],都代表访问从指针指向的元素开始向后数N个元素

	cout << "size of wages array is " << sizeof(wages);
	// 此处可以对数组使用"sizeof()"是因为wages为明确元素的静态数组
		// 结果为3 * 8 = 24
	cout << "size of pw array is " << sizeof(pw);
	// 此处pw是指针变量,"sizeof()"求得的是指针变量本身的大小

	short tell[10];
	cout << tell << " " << &tell << endl;
	cout << tell + 1 << " " << &tell + 1 << endl;
	// tell表示的是数组内第1个元素的地址,&tell表示的是整个数组的地址
		// 此处"tell + 1"会使地址增加2字节,"&tell + 1"会使地址增加20字节

	char flower[10] = "rose";
	cout << flower;
	// 在多数表达式中,char数组名,char指针和""引起的字符串,都常被解释为字符串第一个字符的地址
	// cout对"char*"有特殊读取方式,会从该地址开始打印字符,直到遇见空字符'\0'
		// cout在打印其他类型的指针时,会输出指针对应的地址

	const char* bird = "Wren";
	// 这样声明指针变量时需要使用const,表示该字符串不可被修改
	cout << (void*)bird;
	// 在使用cout直接打印"char*"时,会直接输出指针地址对应的字符串
	// "char*"对应的地址格式:
	// "(void*)str" 

	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};
	inflatable* pl = new inflatable;
	// 可以通过new为指针赋予足以存储结构的内存的地址

	// 下面讲2种访问结构成员的指针表示法:
	//
	// 1.箭头运算符"->"
	cin.getline(pl->name, 20);
	cin >> pl->price;

	// 2.解引用+点号"(*poi_Name)."
	cin >> (*pl).volume;
	cout << pl->name << " " << (*pl).volume << " " << (*pl).price << endl;

	delete pl;
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
	// 此处pa是一个指针变量,它被初始化为指向结构变量s02的地址
	pa->year = 1999;

	antatctica_years_end trio[3];
	// 此处定义了包含三个结构变量的数组
	trio[0].year = 2003;
	cout << trio->year << endl;
		// 数组名字默认为指向第一个元素的指针,此处输出即为trio[0].year

	const antatctica_years_end* arp[3] = {&s01, &s02, &s03};
	// 此处定义了一个包含3个元素的数组,元素类型为指向常量的结构体指针,并分别用三个变量的地址初始化
	cout << arp[1]->year << endl;

	const antatctica_years_end** ppa = arp;
	// arp作为数组名,在表达式中会退化为指向数组首元素的指针(即指向&s01的指针),因此它的类型是二级指针"const antatctica_years_end**"
	// ppa被初始化为arp，两者类型相同
	// 对二级指针解引用(*)一次，就得到一级指针;解引用两次，就得到结构体对象本身
	// 也就是*ppa等价于&s01，**ppa等价于s01
		// 最重要的是明白是"ppa = arp",而不是**ppa

	auto ppb = arp;
	// 此处的auto是C++独特的关键字,根据等号右边的类型来推导等号左边的类型
	cout << (*ppa)->year << endl;
	cout << (*(ppb + 1))->year << endl;
	// 此处让等于arp的ppb指向了下一个元素,也就是指向&s02的指针

	antatctica_years_end* pb = new antatctica_years_end[5];
	// 可以通过new来创建动态结构体数组

	delete[] pb;
}

void Bas18_vector_array()
{
	using std::vector;
	using std::array;
	// 此处仅对vector和array进行介绍

	// 声明vector类的格式: 
	// "vector<type> vec_Name(n_elem)" 创建一个名为vec_Name的vector对象,可以存储n_elem个类型为type的元素
	// n_elem可以是整型常量和整型变量
	// vector对象会在插入/添加值时自动调整长度,n_elem可以被设为0
	vector<double> a1{4};

	// 声明array类的格式: 
	// "array<type, n_elem> arr_Name" 创建一个名为arr_Name的array对象,可以存储n_elem个类型为type的元素
	// n_elem只能是整型常量
	array<double, 4> a2 = {3.14, 2.72, 1.62, 1.41};

	double a3[4] = {1.2, 2.4, 3.6, 4.8};
	a1[0] = 5.0;
	a2[0] = 5.0;
	cout << a1[0] << " " << a2[0] << endl;
}
