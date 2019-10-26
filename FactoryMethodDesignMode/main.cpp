#include "exportOperate.h"
int main() {
    ExportOperate*  operate =new ExportDBOperate();
    operate->exportData("测试数据");
    return 0;
}