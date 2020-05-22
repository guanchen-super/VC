#include <iostream>
#include <string.h>
#include <fstream>

#include <math.h>

#define FLOAT_EPS 1e-6
#define BUFFER_SIZE 4096

bool g_bCombo;						// 是否有套餐
char g_szBuf[BUFFER_SIZE];			// 输入缓冲区

unsigned int g_iComboRate = 0;		// 套餐价格
float g_fComboArea = 0.0;			// 套餐包含面积
float g_fComboRebate = 1.0;			// 套餐折扣率
float g_fAdditionMoney = 0.0;		// 算入套餐的钱

unsigned int g_iNormalRate = 0;		// 非餐价格
float g_fNormalRebate = 1.0;		// 非套餐折扣率

float g_fClosetArea = 0.0;			// 衣柜总面积

void ComputingSolution();

int main(int argc, char **argv)
{
	std::cout << std::endl;
	std::cout << "******************衣柜定制最优解决方案计算工具******************" << std::endl;

step0:
	memset(g_szBuf, 0, BUFFER_SIZE);
	std::cout << std::endl;
	std::cout << "是否有套餐？（Y/N）";
	std::cin >> g_szBuf;
	if (stricmp(g_szBuf, "Y") == 0)
		g_bCombo = true;
	else if (stricmp(g_szBuf, "N") == 0)
		g_bCombo = false;
	else
	{
		std::cout << "输入有误，请重新输入！" << std::endl;
		goto step0;
	}

step1:
	memset(g_szBuf, 0, BUFFER_SIZE);
	std::cout << std::endl;

	if (g_bCombo)
	{
		std::cout << "请输入套餐价格(0,2147483647]：";
		std::cin >> g_szBuf;
		g_iComboRate = atoi(g_szBuf);
		if (0 == g_iComboRate)
		{
			std::cout << "输入套餐套餐价格有误，请重新输入" << std::endl;		
			goto step1;
		}

	step2:
		memset(g_szBuf, 0, BUFFER_SIZE);
		std::cout << std::endl;
		std::cout << "请输入套餐包含的最大投影面积(0.0,3.40282e+038]：";
		std::cin >> g_szBuf;
		g_fComboArea = atof(g_szBuf);
		if (fabs(g_fComboArea) <= FLOAT_EPS)
		{
			std::cout << "输入套餐包含的最大投影面积有误，请重新输入" << std::endl;
			goto step2;
		}

	step3:
		memset(g_szBuf, 0, BUFFER_SIZE);
		std::cout << std::endl;
		std::cout << "请输入套餐折扣率(0.0,0.999]：";
		std::cin >> g_szBuf;
		g_fComboRebate = atof(g_szBuf);
		if (fabs(g_fComboRebate) <= FLOAT_EPS)
		{
			std::cout << "输入套餐折扣率有误，请重新输入" << std::endl;
			goto step3;
		}

	step4:
		memset(g_szBuf, 0, BUFFER_SIZE);
		std::cout << std::endl;
		std::cout << "请输入算入套餐其它项的金额(0.0,3.40282e+038]：";
		std::cin >> g_szBuf;
		g_fAdditionMoney = atof(g_szBuf);
		if (fabs(g_fComboRebate) < FLOAT_EPS || g_fComboRebate > FLT_MAX)
		{
			std::cout << "输入算入套餐其它项的金额，请重新输入" << std::endl;
			goto step4;
		}
	}
	
step5:
	memset(g_szBuf, 0, BUFFER_SIZE);
	std::cout << std::endl;
	std::cout << "请输入非套餐(或超出套餐)每平米投影面积单价(0,2147483647]：";
	std::cin >> g_szBuf;
	g_iNormalRate = atoi(g_szBuf);
	if (0 == g_iNormalRate)
	{
		std::cout << "输入非套餐(或超出套餐)每平米投影面积单价有误，请重新输入" << std::endl;
		goto step5;
	}

step6:
	memset(g_szBuf, 0, BUFFER_SIZE);
	std::cout << std::endl;
	std::cout << "请输入非套餐(或超出套餐)部分的折扣率(0.0,0.999]：";
	std::cin >> g_szBuf;
	g_iNormalRate = atoi(g_szBuf);
	if (0 == g_iNormalRate)
	{
		std::cout << "输入非套餐(或超出套餐)部分的折扣率有误，请重新输入" << std::endl;
		goto step6;
	}

step7:
	memset(g_szBuf, 0, BUFFER_SIZE);
	std::cout << std::endl;
	std::cout << "请输入定制衣柜（或橱柜）的面积(0.0,3.40282e+038]：";
	std::cin >> g_szBuf;
	g_fClosetArea = atof(g_szBuf);
	if (fabs(g_fClosetArea) <= FLOAT_EPS)
	{
		std::cout << "输入定制衣柜（或橱柜）的面积有误，请重新输入" << std::endl;
		goto step7;
	}

	memset(g_szBuf, 0, BUFFER_SIZE);
	ComputingSolution();



	return 0;
}

void ComputingSolution()
{
	std::cout << "正在进行最优解决方案计算..." << std::endl;

	// 重定向控制台输出到磁盘文件
	FILE * pFileOut = nullptr;
	freopen_s(&pFileOut, "optimal_solution.txt", "a+", stdout);

	// 重定向后控制台输出全部写入文件
	std::cout << "\n\n\n\n\n\n" << std::endl;
	std::cout << "最优解决方案基本信息如下：" << std::endl;
	if (g_bCombo)
	{
		std::cout << "套餐价格为：" << g_iComboRate << "元/套" << std::endl;
		std::cout << "套餐包含平米数为：" << g_fComboArea << "平米" << std::endl;
		std::cout << "套餐折扣率为：" << g_fComboRebate << std::endl;
		std::cout << "算入套餐金额为：" << g_fAdditionMoney << "元" << std::endl;
	}
	
	std::cout << "非套餐每平米单价为：" << g_iNormalRate << "元" << std::endl;
	std::cout << "非套餐折扣率为：" << g_fNormalRebate << std::endl;
	std::cout << "需要定制衣柜（或橱柜）的总面积为:" << g_fClosetArea << "平米" << std::endl;

	if (g_bCombo)
	{
		// 计算需要几个套餐
		int nCount = (g_fClosetArea / g_fComboArea);
		if (nCount > 0)
		{
			
		}
		else
		{

		}
	}
	else
	{

	}

	fclose(pFileOut);
}