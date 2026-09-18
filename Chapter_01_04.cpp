/* 执行时弹出警告"该文件包含不能在当前代码页...请将该文件..."属于正常情况,因为文档内中文注释过多 */
/* 修复警告则点击右下角的编码,选择"通过编码重新打开",选择"Unicode(UTF-8带签名)-代码页65001" */
/* 此处推荐一个子体Maple Mono Normal NL NF CN,真的很好看 */

// 以下内容基于Windows平台实现,运行软件为Visual Studio 2026,环境为32位(在上方修改为x86)
// 对于"/**/"注释,仅做拓展说明或占位行,无需深入研究

#include "Chapter_01_04.h"

void Cpp_start()
{
	using namespace std;
	// 可省略下面代码前面的"std::"前缀
	// 会引入整个命名空间,可能会引起命名冲突,比如命名的max函数会与系统的max函数冲突
	// 可只引入单个元素,替换为"using std::cout;"等
	cout << "Hello, World!";
	// ""引起的部分会是输出的字符串,<<表示将字符串发送给cout
	cout << endl;
	// endl表示换行
}

void Simon(int n)
{
	using std::cout;
	// 若不引入整个命名空间,也可以只引入单个元素
	cout << "Simon says touch your toes " << n << " times.\n";
}

int Square(int x)
{
	return x * x;
	// 函数的返回值类型必须与函数声明时的类型一致
}

void Bas01_type_cout()
{
	// "void"表示函数不需要返回值
	using namespace std;
	int carrots_1;
	// "int"表示定义一个整型变量
	// 变量名可以由字母、数字和下划线组成,但不能以数字开头
	// 所有变量必须先定义后使用
	// 可以同时定义多个变量,使用","隔开
	carrots_1 = 25;
	// "="表示赋值,将右边的值赋给左边的变量
	// "="可以连续使用,赋值从右向左进行,如"a = b = c = 5;"表示将5赋给c,再将c的值赋给b,最后将b的值赋给a
	// 可以直接在定义变量时赋值
	carrots_1 = carrots_1 - 1;
	// 变量的值可以通过运算符进行修改
	cout << carrots_1 << endl;
	// 输出变量的值
	// endl也可以与其他输出语句在同一行
	int carrots_2;
	cout << "how many carrots do you have?" << endl;
	cin >> carrots_2;
	// "cin"表示从键盘获取数据,">>"表示将数据传送给变量
	cout << "You have "
		<< carrots_2
		<< " carrots."
		<< endl;
	// 可以只使用一个cout将多条语句分放在多行,也可以全部放在一行
	double x = sqrt(12.25);
	// "double"表示定义一个双精度浮点型变量
	// "sqrt"表示求平方根,数学公式需要使用cmath头文件
	double y = pow(5.0, 3.0);
	// "pow"表示求"5"的"3"次方
	cout << x << " " << y << endl;
}

// 第3章
void Bas02_climits()
{
	// 整型包括"short","int","long","long long","char","bool"等类型,分别占用2,4,4,8,1,1字节
	// int共32位,其中第1位为符号位,第2~32位为数值位,所以int的取值范围为-2^31~2^31-1
	// climits中的符号常量主要有{SHRT/INT/LONG/LLONG}_{MAX/MIN},分别对应四种整型的最大值和最小值
	// 需要整型取值非负时,可以在整型前加上"unsigned",此时整型的取值范围为0~2^32-1
	// "unsigned"对应在符号常量中只需在前面加上"U",符号常量主要有{USHRT/UINT/ULONG/ULLONG}_MAX
	// long整型在不同系统上占用的字节数不同,在mac/Linux系统上占用8字节
	using std::cout;
	using std::endl;
	short sam = SHRT_MAX;
	// 定义sam为short整型变量,并赋值为short整型的最大值
	unsigned short sue = sam;
	cout << sam << " " << sue << endl;
	// sam值为32767, sue值为32767
	sam = sam + 1;
	sue = sue + 1;
	cout << sam << " " << sue << endl;
	// sam值为-32768, sue值为32768
	// short的值超过取值范围从而溢出,从最大值变为最小值
	const int ZERO = 0;
	// "const"表示定义一个常量,常量的值不能被修改,可以在任意位置使用
	// 常见用法为"const typename name = value"
	sam = ZERO;
	sue = ZERO;
	cout << sam << " " << sue << endl;
	// sam值为0, sue值为0
	sam = sam - 1;
	sue = sue - 1;
	cout << sam << " " << sue << endl;
	// sam值为-1, sue值为65535
	// unsigned short的值超过取值范围从而溢出,从最小值变为最大值
}

void Bas03_Hex_dec_oct()
{
	// 16,8,2进制数的开头分别为"0x","0","0b"
	// "decimal"为十进制数,"hexadecimal"为十六进制数,"octal"为八进制数,"binary"为二进制数
	using namespace std;
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
	// char整型用于存储单个字符,通常占用1字节
	// char整型分为char,signed char和unsigned char三种类型
	// signed char通常等价于char,通常直接使用char整型,故不再讨论SCHAR
	// 关于char的符号常量有{CHAR_BIT,CHAR_MAX,CHAR_MIN,UCHAR_MAX},其中bit为char的位数
	using namespace std;
	char ch;
	// 定义ch为char整型变量
	cin >> ch;
	// 从键盘获取一个字符对ch赋值,该字符可以是字母,数字,符号
	// 请注意,此处ch储存的值实际上是所输入字符的ASCII码
	// cin将输入值转化为ASCII码
	int i = ch;
	// 将ch存储的数字赋值给整型变量i
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Add one to the character code:" << endl;
	ch = ch + 1;
	// 将ch的ASCII码加1
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);
	// "cout.put()"成员函数用于输出单个字符,与"cout << ch"完全等价
	// cout将ASCII码转化为对应字符
	cout << endl;
	char sh = '!';
	// 直接给char赋值赋值用''引起字符即可
	cout << sh << endl;
}

void Bas05_escape()
{
	// 转义字符用于表示一些特殊字符,也可以用于表示一些无法直接输入的字符
	// 转义字符以反斜杠"\"开头,后面跟一个或多个字符
	// 常用的转义字符有:
	// \n 换行符(将光标移动到下一行的开头,与endl等价)
	// \t 制表符(每8个字符为一个制表位,和表格一样前端对齐)
	// \b 退格符(将光标回退一格)
	// \r 回车符(会将光标移动到当前行的开头,后字符对前字符进行覆盖)
	// \a 响铃符(?挺好玩的)
	// \\ 反斜杠
	// \' 单引号
	// \" 双引号
	using namespace std;
	cout << "This is a tab:\tEnd of tab.\n";
	cout << "This is a carriage return:\rEnd of carriage return.\n";
	cout << "This is a backslash: \\\n";
	cout << "This is a single quote: \'\n";
	cout << "This is a double quote: \"";
	/*分隔行*/
	cout << "Enter your number:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "Your number is " << code << endl;
	// 请注意,\b只能将光标回退一格,并不会删除字符,若有新字符则覆盖光标处的字符
	// \u 通用字符名,表示一个Unicode字符,后面跟4位16进制数
	cout << "\u4E2d" << endl;
	// Unicode编码为4E2d的字符为"中"
	bool bo1 = -100;
	bool bo2 = true;
	cout << boolalpha << bo1 << " " << noboolalpha << bo2 << endl;
	// 此处(no)boolalpha用来切换bool值的(数字)文字输出
	// bool整型用于存储逻辑值,"true"=1,"false"=0;反之零值="false",非零值="true"
}

void Bas06_float_double()
{
	using std::cout;
	using std::endl;
	// 浮点类型有float,double,long double,可表示带小数部分的数字
	// 对于有效存储位数,通常情况下,float为32位,double为64位,long double为80/96/128位
	// 浮点数存在另一种E表示法,形式为"尾数E指数",意为"尾数×10^指数",例如3.5E6,适用于数量级非常大/小的数
	float fl_a = +3.5e+7;
	// 此处首尾两个加号都可以省略,等价于3.5E7,"e"等价于"E"
	float fl_b = -3.5E-7;
	// 对于非常小的数,可以使指数为负,表示方式为在"E"和"指数"中间加入"-",例如9.11E-31
	cout << fl_a << " " << fl_b << endl;
	float fl_c = fl_a + 1.0f;
	// 对浮点数,默认情况下为double类型,可以通过加后缀来指定类型
	// float类型可加"f"或"F"后缀,long double类型可加"L"后缀
	// 整型变量同样可以加后缀,具体视数字类型而定
	cout << fl_c - fl_a << endl;
	// 大浮点数运算通常会使运算精度降低
	// float只保证6位有效位,指数过大时,此处运行结果为0
}

void Bas07_calculate()
{
	// 算术运算符用来完成基本的算术计算,包括:
	// + 加法
	// - 减法
	// * 乘法
	// / 除法(当两个数均为整数时,结果为商的整数部分)
	// % 求模(运算的两个数必须都是整型)
	using namespace std;
	int ca_a = -20;
	int ca_b = 7;
	cout << ca_a % ca_b << " " << (ca_a / ca_b) * ca_b << " " << ca_a << endl;
	// 若使用"%"运算的两个数中存在负数,则结果应满足:(a/b)*b+a%b=a
	// 运算符的优先级: () > */% > +-
	cout.setf(ios_base::fixed, ios_base::floatfield);
	/* 第一个参数为小数显示形式,"fixed"为定点小数模式,不以E的形式打印;"scientific"为E表示法模式
	   这行代码的作用仅作展示运算输出 */
	cout << "整数除法: 9 / 5 = " << 9 / 5 << endl;
	// 此处结果为1,整数运算舍弃掉了小数部分
	cout << "浮点数除法: 9.0 / 5.0 = " << 9.0 / 5.0 << endl;
	cout << "浮点数&整数混合除法: 9.0 / 5 = " << 9.0 / 5 << endl;
	cout << "double浮点型除法(对比): 1e7 / 9 = " << 1e7 / 9 << endl;
	cout << "float浮点型除法(对比): 1e7f / 9f = " << 1e7f / 9.0f << endl;
	/* 此处结果为1111111.125000, 此处的小数部分是储存为二进制后的近似取舍, 读者无须在意 */
}

void Bas08_type_trans()
{
	// C++可以将一种类型的值赋给另一种类型
	// 对于bool类型变量,被赋予0时转化为false,被赋予非0时转化为true
	using std::cout;
	using std::endl;
	short ca_c = 1000;
	long ca_d;
	ca_d = ca_c;
	cout << ca_d << endl;
	ca_d = 98305;
	ca_c = ca_d;
	cout << ca_c << endl;
	// 将简单类型赋给复杂类型通常不会导致问题,但反过来会导致数值错误,精度降低等问题
	/* C++还允许使用{}进行类型转换,称为"列表初始化",形式为"type name {value}"
	   但列表初始化转换情况十分复杂,此处不予讨论 */
	long thron = 50000;
	cout << short(thron) << endl;
	cout << static_cast<short>(thron) << endl;
	// 强制转换,将变量类似函数一样转换为另一种类型的变量
	// 此处介绍2种强制转换格式:typename(value) -- C/static_cast<typename>(value) -- C++
	// 强制转换不会修改变量本身,而是创建一个新的指定类型的值
	cout << thron << endl;
	auto ca_e = 3.5;
	// auto类型允许程序自行推断变量的类型,但一些时候auto的使用会带来麻烦
	/* 此处提一下缩窄转换的数值是如何计算的:
	   (截断小数部分/浮点->整) large_bit_value % 2 ^ (8 * small_bit) = value,
	   也就是对2^(8*位数)求模,存储的值即为trans_type(value) */
	   /* 缩窄转换:把取值范围更大的类型, 转换为更小的类型
				   如float --> int, int --> short */
}

void Bas09_array()
{
	// 数组是一种数据格式,能存储多个同类型的元素
	// 数组初始化通用格式"typename arrayname[arraysize]",表示名为arrayname的数组能存储arraysize个typename类型元素
	// arraysize不可以是不确定的量,必须是确定的值,如整形常数或常量表达式
	using std::cout;
	int array_exa[2];
	//  array_exa的类型是"int数组",而非单纯的"数组"
	// 不为数组内元素赋值,则数组内元素值不能确定,会输出随机乱数
	array_exa[0] = 5;
	array_exa[1] = 9;
	cout << array_exa[0];
	// 为数组内元素赋值
	int arr_1[4] = { 10, 4 };
	// 直接为数组赋值,按顺序从前到后分配,没有赋值的位置默认为0
	// 只有在定义数组时能这么赋值
	// 不能像变量"a = b"那样让一个数组等于另一个数组
	double arr_2[3]{ 1.2, 1.4, 2.5 };
	// C++初始化数组可以省略"="
	int arr_3[7]{};
	// 大括号内为空时默认所有元素设置为0,等价于arr_3[7]{0}
	char arr_4[4] = { 'h', '!', 115, '\a' };
	// 数组初始化禁止缩窄转换,对于115,其在1字节的取值范围内,可以通过编译
	char arr_5[] = { 'q', '&', 'f' };
	// 在C++中,方括号内不填入数字,编译器会自动计算数组内有多少元素
}

void Bas10_string()
{
	// 字符串是连续字节中的一系列字符,可以存储在char数组中
	// 处理字符串有两种方法,此处介绍C-风格字符串(C-style string)
	using namespace std;
	char cat[4] = { 'd', 'f', ' ', '\0' };
	// C-style string以空字符结尾,写作"\0",ASCII编码为0
	char dog[4] = { 's', 'e', 'f', 'd' };
	// 这只是普通的char数组,并非字符串
	char bird[11] = "Mr. Cheeps";
	// 可以直接让char数组等于字符串,""引起的字符串隐式地包含'\0'
	char chr = 'S';
	// ''和""不能互换
	// 'S'为字符常量,对应ASCII码的83,此处即为对siz赋值83
	// "S"为字符串常量,表示的是'S'和'\0'组成的字符串
	cout << "I want eat cakes\n";
	cout << "I want eat"" cakes\n";
	cout << "I want eat" " cakes\n";
	cout << "I want eat"	" cakes\n";
	cout << "I want eat"
		" cakes" << endl;
	// C++允许拼接两个字符串
	// 两个字符串间可以贴在一起,也可以通过空白(空格,制表符(Tab键),换行符)分隔
	const int Size = 15;
	char name[Size] = "C++Mzrui";
	cout << sizeof(name) << " " << strlen(name) << endl;
	// sizeof运算符会输出数组长度,strlen会输出字符串长度(不算'\0')
	name[3] = '\0';
	cout << name << " " << strlen(name) << endl;
	// '\0'会直接使字符串结束
}

void Bas11_cin_enter()
{
	// 仅使用"cin >>"会在有些时候引起问题
	/* 由于此处函数的特殊性,请读者自行为函数分块后分别执行 */
	using namespace std;
	char name1[20], name2[20];
	cout << "enter one name: \n";
	cin >> name1;
	// 此处输入"Alex Herb"
	cout << "enter another name: \n";
	cin >> name2;
	cout << "first name: " << name1 << " second name: " << name2 << endl;
	// name2的输入看起来被直接跳过了,但name2依旧被分配了字符串
	// 原因是cin使用空白确定字符串结束位置,意味着cin每次只读取一个单词
	// 此时缓冲区内还存在"Herb",第二次cin直接从缓冲区读取了该字符串
	char ch[5];
	cin >> ch;
	// 此处输入"abcdefg"
	cout << ch;
	// 数组只存储了键入字符串前len-1位+'\0'
	char name3[10];
	cin.getline(name3, 10);
	// getline函数格式为"cin.getline(arrayname,arraysize)"
	// getline函数使用换行符(\n或回车)确定字符串结束位置,并清除末尾的\n
	cin.get(name1, 20);
	cin.get(name2, 20);
	// get函数格式为"cin.getline(arrayname,arraysize)"
	// get函数不同于getline,get函数会读取到回车之前,留下换行符
	// 此处第二个cin.get由于读取到第一次遗留下的\n,于是认为输入已经结束,表现为只输入了一次
	cin.get(name1, 20);
	cin.get();
	cin.get(name2, 20);
	// "cin.get()"可以调取输入遗留下的\n
	cin.get(name3, 10).get();
	// 完全等价于分开调用"cin.get(name3,20)"和"cin.get()"
	cin.getline(name1, 20).getline(name2, 20);
	// 完全等价于两次调用getline()
	// 当get读取到空格/getline读取超过size的字符串会在最后读取的位置设置失效位
	// 失效位会使后续cin >>/cin.get/cin.getline失效,表现为直接跳过输入窗口
	/* 分隔行 */
	/* 此处仅展示对get直接回车时的情况 */
	cin.get(name1, 20);
	// 此处直接回车换行
	cin.get(name2, 20);
	cout << name1 << " " << name2 << endl;
	// 第二次输入直接跳过
	cin.clear();
	cin.get();
	cin.get(name2, 20);
	cout << name1 << " " << name2 << endl;
	// clear可以清除设置的失效位
	// clear无法清除字符串过长时残留的字符,之后使用cin会继续读取之前未读取完的字符
	int num1;
	(cin >> num1).get();
	// cin >>输入数字后,需要使用get()清除末尾的\n
	// 等价于分开使用cin >> num1和cin.get()
}

void Bas12_type_string()
{
	// 此处介绍处理字符串的第二种方法:string类
	// 需要使用using namespace std或using std::string来引用string类
	using namespace std;
	char arr[20];
	string str1;
	// 无需同char数组一样声明数组长度
	string str2 = "apple";
	cout << "Enter a word: ";
	cin >> str1;
	cin.get();
	cout << "Here are some words: " << str1 << " " << str2 << endl;
	cout << "The third letter ib " << str2 << " is " << str2[2] << endl;
	// string对象与char数组的使用方式基本相同
	// string对象可以声明为简单变量,并且不受数组长度限制
	string str3{ "I am a test sentence" };
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

void Bas13_structure()
{
	// 结构可以同时存储多种数据类型
	// 结构可以选择放在main函数前或函数内部
	// 前者可用于所有后续函数,后者只能用于所属函数
	using namespace std;
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
	inflatable duck = { "Daphne", 0.12, 9.98 };
	inflatable cayon{ "rumpo", 0.13, 0.22 };
	// 初始化结构使用"={}"或"{}",值列表使用","分隔
	// 值列表可以全部放在同一行
	inflatable mayor{};
	// 大括号内为空则成员都被设置为0,char数组的每个字符都被设置为0
	// 结构内成员的值不允许缩窄转换
	struct infe { std::string name; };
	// 结构内成员也可以指定为string对象
	mayor = duck;
	cout << mayor.name << " " << mayor.volume << endl;
	// 结构中的成员可以被赋予另一个结构中成员的值
	struct perks {
		int key_number;
		char car[12];
	} mr_smith, mr_jones = { 7,"packard" };
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

void Bas14_enumeration()
{
	// enum可以定义一种创建符号常量的新类型
	enum spectrum { red, orange, yellow, green, blue, violet, indigo, ultraviolet };
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
	enum bits { zero = 0, one = 1, second = 100, third };
	// 可以对对枚举的符号常量进行赋值,未赋值的枚举量默认比前一位大1
	bits myflag;
	myflag = bits(6);
	// 这种情况是被允许的,访问值位于枚举量的取值范围内,输出结果即为访问值6
}
void Bas15_pointer()
{
	// 指针是一个变量,存储的不是值本身,而是值的地址
	using namespace std;
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
	/* 分隔行 */
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

void Bas16_pointer_arithmetic()
{
	// 对地址进行+-运算会根据地址对应的数据对象类型的字节数进行运算
	using namespace std;
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };
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
	/* 分隔行 */
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
	/* 分隔行 */
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

void Bas17_type_combination()
{
	// 数组,结构,指针可以以各种方式来结合使用
	using namespace std;
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
	const antatctica_years_end* arp[3] = { &s01, &s02, &s03 };
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
}

void Bas18_vector_array()
{
	// 此处仅对vector和array进行介绍
	using namespace std;
	// 模版类vector类包含在std中,需要using声明
	// 声明vector类的格式:"vector<typename> vectorname(n_elem)"
	// 意思是创建一个名为vectorname的vector对象,可以存储n_elem个类型为typename的元素
	// n_elem可以是整型常量和整型变量
	// vector对象会在插入/添加值时自动调整长度,n_elem可以被设为0
	vector<double> a1{ 4 };
	// 模板类array类包含在std中,需要using声明
	// 声明array类的格式:"array<typename, n_elem> arrayname"
	// 意思是创建一个名为arrayname的array对象,可以存储n_elem个类型为typename的元素
	// n_elem只能是整型常量
	array<double, 4> a2 = { 3.14, 2.72, 1.62, 1.41 };
	double a3[4] = { 1.2, 2.4, 3.6, 4.8 };
	a1[0] = 5.0;
	a2[0] = 5.0;
	cout << a1[0] << " " << a2[0] << endl;
}

void Test_code()
{
	using std::cout;
	cout << "Hello, C++!\n";
}
