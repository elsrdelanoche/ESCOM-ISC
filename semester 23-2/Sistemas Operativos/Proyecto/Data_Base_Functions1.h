#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Product
{
    char*   Product_Name;
    float     Price_per_unit;
    unsigned int     Stock;
    unsigned int     Attributes_amount;
    unsigned int*    Extra_sub_attribute_value_amount;
    char**  Attribute;
    char*** Attribute_value;

}Product;
typedef struct Class
{
    char* Class_Name;
    unsigned int Products_amount;
    Product** Products;

}Class;
typedef struct Data_Base
{
    unsigned int Classes_amount;
    Class** Classes;
}Data_Base;

char* Load_DB_Text(char* DB_File_Name){
    
    FILE* DB_File;
    DB_File = fopen(DB_File_Name,"r");
    if(DB_File == NULL){printf("Error loading data base!!\n");fclose(DB_File);return NULL;}

    //measuring the file
    fseek(DB_File,0,SEEK_END);
    unsigned long DB_File_size = ftell(DB_File);
    fseek(DB_File,0,SEEK_SET);
    
    //Alocating memory
    char* DB_File_Text = (char*)malloc(DB_File_size);
    if (DB_File_Text == NULL){printf("Error Allocating memory!!\n");fclose(DB_File);return NULL;}

    //Loading the BD_Text
    size_t Bytes_Read = fread(DB_File_Text,sizeof(char),DB_File_size,DB_File);
    if(Bytes_Read != DB_File_size){printf("Error reading file!!\n");free(DB_File_Text);fclose(DB_File);return NULL;}

    //Adding null-character at the end
    DB_File_Text[DB_File_size-1] = '\n';
    fclose(DB_File);
    return DB_File_Text;
}
char* Append_Char(char* Buffer,char New_Char){
    char* New_Buffer;
    if (Buffer == NULL)
    {
        New_Buffer = (char*)calloc(sizeof(char),2);
        if (New_Buffer == NULL)
        {
            printf("Error Allocating New Buffer!!\n");
            return NULL;
        }else{
            New_Buffer[0] = New_Char;
            return New_Buffer;
        } 
    }else{
        unsigned int lenght = strlen(Buffer);
        New_Buffer = (char*)realloc(Buffer,sizeof(char)*(lenght+2));
        New_Buffer[lenght] = New_Char;
        New_Buffer[lenght+1] = '\0';
        return New_Buffer;
    }
}
char** Append_String(char** Array,unsigned int* lenght,char* string){
    char** New_Array;
    if (Array == NULL)
    {
        New_Array = (char**)calloc(sizeof(char**),1);
        if(New_Array == NULL){printf("Error Allocating Array!!\n");return NULL;}
        New_Array[0] = string;
        *lenght = 1;
        return New_Array;
    }else{
        New_Array = (char**)realloc(Array,sizeof(char*)*(*lenght+1));
        if(New_Array == NULL){printf("Error Resizing Array!!\n");return NULL;}
        New_Array[*lenght] = string;
        *lenght += 1;
        return New_Array;
    }
}
Class** Add_Class(Class** Current_Classes,unsigned int* Current_Classes_Amount,char* New_Class_Name){
    Class** New_Classes_Array;
    if (*Current_Classes_Amount == 0)
    {
        New_Classes_Array = (Class**)calloc(sizeof(Class*),1);
        if (New_Classes_Array == NULL){printf("Error Allocating Classes!!\n");return NULL;}
        else{
            New_Classes_Array[0] = (Class*)calloc(sizeof(Class),1);
            New_Classes_Array[0]->Class_Name = New_Class_Name;
            *Current_Classes_Amount += 1;
            return New_Classes_Array;
        }
    }else{
        New_Classes_Array = (Class**)realloc(Current_Classes,sizeof(Class*)*((*Current_Classes_Amount) + 1));
        if (New_Classes_Array == NULL){printf("Error Resizing Classes!!\n");return NULL;}
        else{
            New_Classes_Array[*Current_Classes_Amount] = (Class*)calloc(sizeof(Class),1);
            New_Classes_Array[*Current_Classes_Amount]->Class_Name = New_Class_Name;
            *Current_Classes_Amount += 1;
            return New_Classes_Array;
        }
    }
}
Product** Add_Product(Product** Current_Products,unsigned int* Current_Products_Amount,char* New_Product_Name){
    Product** New_Products_Array;
    if (*Current_Products_Amount == 0)
    {
        New_Products_Array = (Product**)calloc(sizeof(Product*),1);
        if (New_Products_Array == NULL){printf("Error Allocating Products!!\n");return NULL;}
        else{
            New_Products_Array[0] = (Product*)calloc(sizeof(Product),1);
            New_Products_Array[0]->Product_Name = New_Product_Name;
            New_Products_Array[0]->Attribute = (char**)calloc(sizeof(char*),1);
            New_Products_Array[0]->Attribute = NULL;
            *Current_Products_Amount = 1;
            return New_Products_Array;
        }
    }else{
        New_Products_Array = (Product**)realloc(Current_Products,sizeof(Product*)*((*Current_Products_Amount) + 1));
        if (New_Products_Array == NULL){printf("Error Resizing Products!!\n");return NULL;}
        else{
            New_Products_Array[*Current_Products_Amount] = (Product*)calloc(sizeof(Product),1);
            New_Products_Array[*Current_Products_Amount]->Product_Name = New_Product_Name;
            New_Products_Array[*Current_Products_Amount]->Attribute = (char**)calloc(sizeof(char*),1);
            New_Products_Array[*Current_Products_Amount]->Attribute = NULL;
            *Current_Products_Amount += 1;
            return New_Products_Array;
        }
        
    }
    

}
char** Add_Attribute(char** Current_Attributes,unsigned int* Current_Attributes_Amount,char* New_Attribute_Text){
    char** New_Attributes_Array;
    if (*Current_Attributes_Amount == 0)
    {
        New_Attributes_Array = (char**)calloc(sizeof(char*),1);
        if (New_Attributes_Array == NULL){printf("Error Allocating Attributes!!\n");return NULL;}
        else{
            New_Attributes_Array[0] = New_Attribute_Text;
            *Current_Attributes_Amount = 1;
            return New_Attributes_Array;
        }
    }else{
        New_Attributes_Array = (char**)realloc(Current_Attributes,sizeof(char*)*((*Current_Attributes_Amount) + 1));
        if (New_Attributes_Array == NULL){printf("Error Resizing Attributes!!\n");return NULL;}
        else{
            New_Attributes_Array[*Current_Attributes_Amount] = New_Attribute_Text;
            *Current_Attributes_Amount += 1;
            return New_Attributes_Array;
        }
    }
}
char*** Add_Attribute_Value(char*** Current_Attributes_OR_Values,unsigned int* Current_Attributes_OR_Values_Amount,char** New_Attribute_OR_Value_Text){
    char*** New_Attributes_OR_Values_Array;
    if (*Current_Attributes_OR_Values_Amount == 0)
    {
        New_Attributes_OR_Values_Array = (char***)calloc(sizeof(char**),1);
        if (New_Attributes_OR_Values_Array == NULL){printf("Error Allocating Attributes!!\n");return NULL;}
        else{
            New_Attributes_OR_Values_Array[0] = (char**)calloc(sizeof(char*),1);
            New_Attributes_OR_Values_Array[0] = New_Attribute_OR_Value_Text;
            return New_Attributes_OR_Values_Array;
        }
    }else{
        New_Attributes_OR_Values_Array = (char***)realloc(Current_Attributes_OR_Values,sizeof(char**)*((*Current_Attributes_OR_Values_Amount)));
        if (New_Attributes_OR_Values_Array == NULL){printf("Error Resizing Attributes!!\n");return NULL;}
        else{
            New_Attributes_OR_Values_Array[*Current_Attributes_OR_Values_Amount-1] = (char**)calloc(sizeof(char*),1);
            New_Attributes_OR_Values_Array[*Current_Attributes_OR_Values_Amount-1] = New_Attribute_OR_Value_Text;
            return New_Attributes_OR_Values_Array;
        }
    }
}
char*   Get_Class_Name(char* DB_Text,unsigned int* Char_Ptr){
    unsigned int ptr;
    char* Buffer = NULL;
    ptr = *Char_Ptr;
    while (DB_Text[ptr] != '{')
    {
        Buffer = Append_Char(Buffer,DB_Text[ptr]);
        ptr += 1;
    }
        *Char_Ptr = ptr+1;
        return Buffer;
}
int   Get_Stock(char* DB_Text,unsigned int* Char_ptr){
    char* Buffer = NULL;
    while (DB_Text[*Char_ptr] != '>')
    {
        Buffer = Append_Char(Buffer,DB_Text[*Char_ptr]);
        *Char_ptr+=1;
    }
    *Char_ptr += 1;
    return atoi(Buffer);
}
char*   Get_Product_Name(char* DB_Text,unsigned int* Char_ptr){
   char* Buffer = NULL;
   while (DB_Text[*Char_ptr] != '[')
    {
        Buffer = Append_Char(Buffer,DB_Text[*Char_ptr]);
        *Char_ptr += 1;
    }
    *Char_ptr+=1;
    return  Buffer;
}
char*   Get_Attribute(char* DB_Text,unsigned int* Char_ptr){
    char* Buffer = NULL;
   while (DB_Text[*Char_ptr] != ':')
    {
        Buffer = Append_Char(Buffer,DB_Text[*Char_ptr]);
        *Char_ptr += 1;
    }
    *Char_ptr+=1;
    return  Buffer;
}
char**   Get_Attribute_Values(char* DB_Text,unsigned int* Char_ptr,unsigned int* Values_amount){
    char** Array_Buffer = NULL;
    char*  Buffer = NULL;
    *Values_amount = 0;
    while (DB_Text[*Char_ptr] != ',' && DB_Text[*Char_ptr] != ']')
    {
        Buffer = Append_Char(Buffer,DB_Text[*Char_ptr]);
        *Char_ptr += 1;
        if (DB_Text[*Char_ptr] == '&')
        {
            Array_Buffer = Append_String(Array_Buffer,Values_amount,Buffer);
            *Char_ptr += 1;
            Buffer = NULL;
        }
        
    }
    Array_Buffer = Append_String(Array_Buffer,Values_amount,Buffer);
    return Array_Buffer;
}

float Get_Price(char* DB_Text,unsigned int* Char_ptr){
    char* Buffer = NULL;
    while (DB_Text[*Char_ptr] != ',' && DB_Text[*Char_ptr] != '}')
    {
        Buffer = Append_Char(Buffer,DB_Text[*Char_ptr]);
        *Char_ptr += 1;
    }
        *Char_ptr += 1;
        return atof(Buffer);
    
}
void PrintDB(Data_Base* DB){
    printf("Clases %d\n",DB->Classes_amount);
    for (int i = 0; i < DB->Classes_amount ; i++)
    {
        printf("Clase: %s\n",DB->Classes[i]->Class_Name);
        for (int o = 0; o < DB->Classes[i]->Products_amount; o++)
        {
            printf("\tProducto: %s\n",DB->Classes[i]->Products[o]->Product_Name);
            printf("\tStock: %d\n",DB->Classes[i]->Products[o]->Stock);
            printf("\tPrecio: %.2f\n",DB->Classes[i]->Products[o]->Price_per_unit);
            printf("\tCantidad_Atributos: %d\n",DB->Classes[i]->Products[o]->Attributes_amount);
            for (int u = 0; u < DB->Classes[i]->Products[o]->Attributes_amount; u++)
            {
                printf("\t\tAttributo : %s\n",DB->Classes[i]->Products[o]->Attribute[u]);
                for (int e = 0; e < DB->Classes[i]->Products[o]->Extra_sub_attribute_value_amount[u] ; e++)
                {
                    printf("\t\t\tValor %d: %s\n",e,DB->Classes[i]->Products[o]->Attribute_value[u][e]);
                }   
            }   
        }
    }
}
Data_Base* Load_DB_From_Text(char* DB_Text){
    unsigned int l = 0;
    unsigned int m = 0;
    unsigned int n = 0;
    unsigned int Char_ptr = 0;
    char* Char_Buffer = NULL;
    char** string_Array_Buffer = NULL;
    int Stock;
    //Inizialization of the DB structure
    Data_Base* DB = (Data_Base*)calloc(1,sizeof(Data_Base));
    DB->Classes_amount = 0;
    l = 0;
    Load_Class:
    Char_Buffer = Get_Class_Name(DB_Text,&Char_ptr);
    DB->Classes = Add_Class(DB->Classes,&DB->Classes_amount,Char_Buffer);
    
    m = 0;
    Get_Stock_And_Product:
    Stock = Get_Stock(DB_Text,&Char_ptr);
    
    Char_Buffer = Get_Product_Name(DB_Text,&Char_ptr);    

    DB->Classes[l]->Products = Add_Product(DB->Classes[l]->Products,&DB->Classes[l]->Products_amount,Char_Buffer);
    DB->Classes[l]->Products[m]->Stock = Stock;

    n = 0;
    Load_Attribute:
    Char_Buffer = Get_Attribute(DB_Text,&Char_ptr);
    DB->Classes[l]->Products[m]->Attribute = Add_Attribute(DB->Classes[l]->Products[m]->Attribute,&DB->Classes[l]->Products[m]->Attributes_amount,Char_Buffer);
    DB->Classes[l]->Products[m]->Extra_sub_attribute_value_amount = Add_Extra_Sub_Attribute(DB->Classes[l]->Products[m]->Extra_sub_attribute_value_amount,DB->Classes[l]->Products[m]->Attributes_amount);
    string_Array_Buffer = Get_Attribute_Values(DB_Text,&Char_ptr,&DB->Classes[l]->Products[m]->Extra_sub_attribute_value_amount[DB->Classes[l]->Products[m]->Attributes_amount-1]);
    DB->Classes[l]->Products[m]->Attribute_value = Add_Attribute_Value(DB->Classes[l]->Products[m]->Attribute_value,&DB->Classes[l]->Products[m]->Attributes_amount,string_Array_Buffer);
    
    if (DB_Text[Char_ptr] != ']')
    {
        n += 1;
        Char_ptr+=1;
        goto Load_Attribute;
    }
    
    Load_Price_Per_Unit:
    Char_ptr+=1;
    DB->Classes[l]->Products[m]->Price_per_unit = Get_Price(DB_Text,&Char_ptr);
    if (DB_Text[Char_ptr-1] == ',')
    {
        m+=1;
        goto Get_Stock_And_Product;
    }
    if (DB_Text[Char_ptr-1] == '}')
    {
        if (DB_Text[Char_ptr] == ';'){
            PrintDB(DB);
            return DB;
        }
        l+=1;
        Char_ptr += 1;
        goto Load_Class;
    }
}

