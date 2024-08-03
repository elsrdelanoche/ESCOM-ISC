#include "Data_Base_Functions.h"

int main(int argc, char const *argv[])
{
    char* Inventory_Text = Load_DB_Text("Base_Datos/DB.c");
    Data_Base* Data = Load_DB_From_Text(Inventory_Text);
    return 0;
}
