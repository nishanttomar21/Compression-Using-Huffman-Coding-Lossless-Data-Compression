/*
 
 Programme Conceptualised And Developed By:
 Nishant Tomar
 Dipak Rai
 
 Batch:     B7
 
 UNIVERSITY :  JIIT,NOIDA SECTOR 62
 
 Project Title: Huffman Coding( Compression )
 Copyright:  2015
 
 Programme Version : 1.0.1
 Last Update On: 13.05.2015
 All Rights Reserved To The 2 Programmers Of This Program Only
 
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>


typedef struct Node
{
    
    long int freq;
    int character;
    struct Node *next;
    
}Node;



typedef struct List
{
    
    struct List *next;
    Node *node;
    
}List;



typedef struct Node_k                                                                                   // Structure For K
{
    
    struct Node_k *next;
    int value;
    
}Node_k;



typedef struct tree
{
    
    long int freq;
    int character;
    struct tree *left_child;
    struct tree *right_child;
    struct tree *next;
    
}tree;



typedef struct array
{
    
    int character;
    char bin[20];
    
}array;



Node *start_1D  , *end_1D , *temp_1D;                                                                   // Globally Declared
Node_k *start_k , *temp_k , *end_k;
List *start_2D , *end_2D , *temp_2D;



Node* freq_calculation()
{
    
    int *frequency = (int*) calloc (sizeof(int),127);
    Node *start_1D = NULL;
    FILE *fp1 , *fp2;
    int i;
    char ch;
    
    fp1 = fopen("input.txt","r");
    fp2 = fopen("frequency.txt","w");
    
    if( fp1 == NULL )                                                                                   // Checking If File Is Empty
    {
        
        printf("\n\nFILE NOT FOUND ( SOURCE FILE )!!\n\n\n");
        exit(1);
        
    }
    
    while( (ch = getc(fp1)) != EOF )                                                                    // Calculating The Frequency
    {
        
        frequency[ (int)ch ]++;
        
    }
    
    
    fprintf(fp2,"FREQUENCY            CHARACTER              ASCI\n\n\n");
    
    for( i = 0 ; i < 127 ; i++ )                                                                        // Inputting Frequency And Its Respective Character To A File
    {
        
        if( frequency[i] > 0 )
        {
            
            if( i == 10 || i == 32 )
            {
                
                if( i == 10 )
                    fprintf(fp2," %d                   Lines                   %d\n\n",frequency[i],i);
                
                if( i == 32 )
                    fprintf(fp2," %d                 Spaces                   %d\n\n",frequency[i],i);
                
            }
            
            else
            {
                
                fprintf(fp2," %d                    %c                    %d\n\n",frequency[i],i,i);
                
            }
            
        }
        
        
    }
    
    for( i = 0 ; i < 127 ; i++ )                                                                        // Inputting Frequency And Character Into A Link-List
    {
        
        if( frequency[i] > 0 )
        {
            
            temp_1D = (Node*) malloc (sizeof(Node));
            
            temp_1D->freq = frequency[i];
            temp_1D->character = i;
            temp_1D->next = NULL;
            
            if(start_1D == NULL)
            {
                
                start_1D = temp_1D;
                end_1D = temp_1D;
                
            }
            
            else
            {
                
                end_1D->next = temp_1D;
                end_1D = temp_1D;
                
            }
            
        }
        
        
    }
    
    fclose(fp1);
    fclose(fp2);
    
    return start_1D;
    
    /*
     
     NOTE : The unit separator ASCII character (ASCII 31, octal 37), is visible in Vim as a ^_. But if I print the same file to the terminal, the character is invisible. This causes the fields on a line to  get stuck together. ASCII codes under 31, and 127, are intended to cause a terminal or device to do something (hence why they are called control codes), or stand for something in a protocol (like EOT or SOH), as opposed to displaying something. It hearkens back when terminals were typewriter-like devices and things like telling a teletype to carriage-return   were physically needed. Editors may choose to render them using "^" notation since you are editing something and don't want to terminal to actually do what the control codes are asking.

         Carriage return means to return to the beginning of the current line without advancing downward. The name comes from a printer's carriage, as monitors were rare when the name was coined. This is commonly escaped as "\r", abbreviated CR, and has ASCII value 13 or 0xD.
     

     */

    
}



Node_k* reverse_k( Node_k *start_k )
{
    
    Node_k *current_k , *previous_k = NULL , *temp_k;
    
    temp_k = start_k;
    
    while( temp_k != NULL )                                                                             // Reversing The Values Of K
    {
        
        current_k = temp_k->next;
        temp_k->next = previous_k;
        previous_k = temp_k;
        temp_k = current_k;
        
    }
    
    start_k = previous_k;
    
    return start_k;
    
    
}



Node_k* generating_k( int size )
{
    
    long int k = 1 , n = 0 , i , value;
    Node_k *start_k = NULL;
    FILE *fp;
    
    fp = fopen("sequence.txt","w");
    
    while( k < size )                                                                                   // Generating The Values Of k
    {
        
        for( i = 0 ; i <= n ; i++ )
        {
            
            if( k < size )
            {
                
                k = pow ( 2 , (n-i) ) * pow ( 3 , i );                                                  // Formula For Pyramid Form
                
                if( k > size )
                    break;
                
                if( i == n )
                {
                    
                    value = k;                                                                          // Saving Last Right Corner From Pattern
                    
                }
                
                
            }
            
            
        }
        
        n++;
        
        
    }
    
    
    k = 1;
    n = 0;
    
    
    
    while( k != value )                                                                                 // Copying Values Of k To A File
    {
        
        for( i = 0 ; i <= n ; i++ )
        {
            
            if( k < size )
            {
                
                k = pow ( 2,(n-i) ) * pow ( 3,i );
                
                if( k > size )
                    break;
                
                fprintf(fp,"%ld\n",k);
                
            }
            
            
        }
        
        n++;
        
        
    }
    
    
    fclose(fp);
    
    fp = fopen("sequence.txt","r");
    
    if( fp == NULL )                                                                                   // Checking If File Is Empty
    {
        
        printf("\n\nFILE NOT FOUND ( SEQUENCE.TXT )!!\n\n\n");
        exit(1);
        
    }
    
    
    while( (fscanf(fp,"%ld",&k) ) != EOF)                                                              // Inputting Values Of k Into A Link-List
    {
        
        temp_k = (Node_k*) malloc (sizeof(Node_k));
        
        temp_k->value = k;
        
        temp_k->next = NULL;
        
        
        if( start_k == NULL )
        {
            
            start_k = temp_k;
            end_k = temp_k;
            
        }
        
        else
        {
            
            end_k->next = temp_k;
            end_k = temp_k;
            
        }
        
        
    }
    
    start_k = reverse_k( start_k );
    
    fclose(fp);
    
    return start_k;


    
}



Node* sorting( Node *start )                                                                            // Sorting Function
{
    
    Node *temp1 , *temp2;
    long int f;
    int c;
    
    for( temp1 = start ; temp1 != NULL ; temp1 = temp1->next )
    {
        
        for( temp2 = temp1->next ; temp2 != NULL ; temp2 = temp2->next )
        {
            
            if( temp1->freq > temp2->freq )
            {
                
                f = temp1->freq;                                                                         // Swapping Frequency
                temp1->freq = temp2->freq;
                temp2->freq = f;
                
                c = temp1->character;                                                                    // Swapping Corresponding Character
                temp1->character = temp2->character;
                temp2->character = c;
                
            }
            
            
        }
        
    }
    
    return start;
    
    
}



Node* shell_sort( Node *start_1D , Node_k *start_k , int size )
{
    
    long int l , i = 0 , k;
    List *start_2D = NULL;
    Node_k *save_k;
    Node *save_1D;
    clock_t time;
    FILE *fp;
    double d;

    fp = fopen("sorted.txt","w");
    
    temp_k = start_k;
    
    time = clock();                                                                                     // Start Time

    while( temp_k != NULL )                                                                             // Selecting Value Of K
    {
        
        k = temp_k->value;
        start_2D = NULL;
        temp_1D = start_1D;
        i = 0;
        
        
        while( temp_1D != NULL )                                                                        // 1D -> 2D
        {
            
            for( ; i < k ; i++ )
            {
                
                temp_2D = (List*) malloc (sizeof(List));
                
                save_1D = temp_1D->next;
                temp_1D->next = NULL;
                temp_2D->node = temp_1D;
                temp_2D->next = NULL;
                
                if( start_2D == NULL )
                {
                    
                    start_2D = temp_2D;
                    end_2D = temp_2D;
                    
                }
                
                else
                {
                    
                    end_2D->next = temp_2D;
                    end_2D = temp_2D;
                    
                }
                
                temp_1D = save_1D;
                
                if( i == k - 1 )
                temp_2D = start_2D;
                
            }
            
            save_1D = temp_1D->next;
            
            if( temp_2D == NULL )
            temp_2D = start_2D;
            
            temp_1D->next = temp_2D->node;
            temp_2D->node = temp_1D;
            temp_2D = temp_2D->next;
            temp_1D = save_1D;
            
        }
        
        
        for( temp_2D = start_2D ; temp_2D != NULL ; temp_2D = temp_2D->next )                           // Calling Sorting Function
        temp_2D->node = sorting(temp_2D->node);
        
        
        start_1D = NULL;
        temp_2D = start_2D;
        l = 0;
        
        
        while( l != size )                                                                              // 2D -> 1D
        {
            
            l++;
            
            temp_1D = temp_2D->node;
            
            temp_2D->node = temp_1D->next;
            temp_2D = temp_2D->next;
            
            temp_1D->next = NULL;
            
            if( temp_2D == NULL )
                temp_2D = start_2D;
            
            if( start_1D == NULL )
            {
                
                start_1D = temp_1D;
                end_1D = temp_1D;
                
            }
            
            else
            {
                
                end_1D->next = temp_1D;
                end_1D = temp_1D;
                
            }
            
            
        }
        
        
        temp_k = temp_k->next;
        
        temp_2D = start_2D;
        
        
        while( temp_2D != NULL )                                                                         // Freeing 2D Link List
        {
            
            start_2D = temp_2D->next;
            free(temp_2D);
            temp_2D = start_2D;
            
        }
        
        
    }
    
    d = ( clock() - time ) / (double)CLOCKS_PER_SEC;                                                    // End Time
    
    printf("\n\n\nSORTING TIME: %f SECONDS\n\n\n\n",d);                                                 // Printing Time Taken For Sorting
    
    fprintf(fp,"FREQUENCY           CHARACTER              ASCI\n\n\n");
    
    for( temp_1D = start_1D ; temp_1D != NULL ; temp_1D = temp_1D->next )                               // Inputting Sorted Frequency To A File
    {
        
        if( (temp_1D->character == 10) || (temp_1D->character == 32) )
        {
            
            if( temp_1D->character == 10 )
                fprintf(fp," %ld                   Lines                   %d\n\n",temp_1D->freq,temp_1D->character);
            
            if( temp_1D->character == 32 )
                fprintf(fp," %ld                   Spaces                   %d\n\n",temp_1D->freq,temp_1D->character);
            
        }
        
        else
        {
            
            fprintf(fp," %ld                    %c                    %d\n\n",temp_1D->freq,temp_1D->character,temp_1D->character);
            
        }
        
        
    }
    
    temp_k = start_k;
    
    while( temp_k != NULL )                                                                               // Freeing Link List Of K
    {
        
        save_k = temp_k->next;
        free(temp_k);
        temp_k = save_k;
        
    }
    
    fclose(fp);
    
    /*
     
     Three Step Sorting :
     
     a : Inserting 1D Link List Into 2D Link List With Respect To The Value Of k.
     b : Calling Sorting Function.
     c : Converting 2D Link List Back To 1D Link List.
     
     */
    
    return start_1D;
    
    
}




tree* sort_tree( tree *start )                                                                            // Sorting Function
{
    
    long int f;
    int c;
    tree *trave1 , *trave2 , *temp_r , *temp_l;
    
    for( trave1 = start ; trave1 != NULL ; trave1 = trave1->next )
    {
        
        for( trave2 = trave1->next ; trave2 != NULL ; trave2 = trave2->next )
        {
            
            if( trave1->freq > trave2->freq )
            {

                f = trave1->freq;                                                                       // Swapping Frequency
                trave1->freq = trave2->freq;
                trave2->freq = f;
                
                c = trave1->character;                                                                  // Swapping Corresponding Character
                trave1->character = trave2->character;
                trave2->character = c;
              
                temp_l = trave1->left_child;                                                            // Swapping Left Child
                trave1->left_child = trave2->left_child;
                trave2->left_child = temp_l;

                temp_r = trave1->right_child;                                                           // Swapping Right Child
                trave1->right_child = trave2->right_child;
                trave2->right_child = temp_r;
                
            }
            
            
        }
        
    }

    return start;
    

}



void generating_binary( tree *root , int *arr , int top , FILE *fp , FILE *fp1)                         // Pre-Fix Property ( Recursion )
{
    
    int j;
    
    if( root->left_child )                                                                              // Assigning 0 To Left Edge And Recur
    {

        arr[top] = 0;
        generating_binary( root->left_child , arr , top + 1 , fp , fp1 );
    
    }
    
    if( root->right_child )                                                                             // Assigning 1 To Right Edge And Recur
    {
        
        arr[top] = 1;
        generating_binary( root->right_child , arr , top + 1 , fp , fp1 );
    
    }
    
    if( (root->left_child) == NULL && (root->right_child) == NULL )                                     // Checking If It's A Leaf Node
    {

        fprintf(fp1,"%d\n",root->character);
        
        for( j = 0 ; j < top ; j++ )
        fprintf(fp,"%d",arr[j]);
        
        fprintf(fp,"\n");
        top = 0;
 
    }
    


}
 


void huffman_tree( Node *start_1D , int size )
{

    tree *trave , *trave1 , *trave2 , *start_tree = NULL , *end_tree , *branch_node , *save_tree;
    int top = 0 , i = 0;
    Node *save_1D;
    FILE *fp , *fp1;
    
    fp = fopen("binary.txt","w");
    fp1 = fopen("character.txt","w");
    
    for( temp_1D = start_1D ; temp_1D != NULL ; temp_1D = temp_1D->next )                               // Creating Tree List
    {
        
        trave = (tree*) malloc (sizeof(tree));
        
        trave->left_child = NULL;
        trave->right_child = NULL;
        trave->freq = temp_1D->freq;
        trave->character = temp_1D->character;
        
        if( start_tree == NULL )
        {
            
            start_tree = trave;
            end_tree = trave;
            
        }
        
        else
        {
            
            end_tree->next = trave;
            end_tree = trave;
            
        }

        
    }

    do                                                                                                  // Creating Huffman Tree
    {

        start_tree = sort_tree( start_tree );                                                           // Calling Sorting Function

        trave1 = start_tree;
        trave2 = start_tree->next;
   
        branch_node = (tree*) malloc (sizeof(tree));
        
        branch_node->freq = ( trave1->freq + trave2->freq );
        branch_node->left_child = trave1;
        branch_node->right_child = trave2;
        branch_node->next = trave2->next;
        trave1->next = NULL;
        trave2->next = NULL;
        start_tree = branch_node;

    }while( start_tree->next != NULL );

    temp_1D = start_1D;
    
    while( temp_1D != NULL )                                                                            // Freeing 1D Link List
    {
        
        save_1D = temp_1D->next;
        free(temp_1D);
        temp_1D = save_1D;
        
    }
    
    int *arr = (int*) malloc (sizeof(int) * 50);
    
    generating_binary( start_tree , arr , top , fp , fp1 );                                            // Function For Assigning Binary
    
    fclose(fp);
    fclose(fp1);

    free(arr);
    
    trave = start_tree;
    
    while( trave != NULL )                                                                              // Freeing Tree
    {
        
        save_tree = trave->next;
        free(trave);
        trave = save_tree;
        
    }
    
    fclose(fp);
    fclose(fp1);
    
    
}



void metadata( array *binary )                                                                          // Saving Binary And Corresponding Character To An Array
{
    
    FILE *fp , *fp1;
    char ch[20];
    int j , k = 0 , i;
    
    fp = fopen("binary.txt","r");
    fp1 = fopen("character.txt","r");

    while( fgets(ch,20,fp) )
    {
        
        strcpy( binary[k].bin , ch );
        k++;
        
    }
          
    k = 0;
    
    while( (fscanf(fp1,"%d",&j)) !=EOF )
    {
        
        binary[k].character = j;
        k++;
        
    }
  
    fclose(fp);
    fclose(fp1);
    
}



int save_binary( array *binary , int size )
{
    
    FILE *fp , *fp1 , *fp2 , *fp3;
    char value;
    int i , count;
    int x = 450000;
    int n;
    
    fp = fopen("input.txt","r");
    fp1 = fopen("trash.txt","w");
    fp2 = fopen("trash2.txt","w");
    fp3 = fopen("savebinary.txt","w");
    
    if( fp1 == NULL )                                                                                   // Checking If File Is Empty
    {
        
        printf("\n\nFILE NOT FOUND ( SOURCE FILE )!!\n\n\n");
        exit(1);
        
    }
    
    while( (value = getc(fp)) != EOF )
    {

        for( i = 0 ; i < size ; i++ )
        {
        
            if( (int)value == binary[i].character )
            fprintf(fp1,"%s",binary[i].bin);
            
        }
        
    }
    
    fclose(fp1);
    
    fp1 = fopen("trash.txt","r");
 
    while( (value = getc(fp1)) != EOF )
    {
        
        if( (int)value == 10 )
            if( (value = getc(fp1)) == EOF )
                break;
        
        fprintf(fp2,"%c",value);
        
    }
    
    fclose(fp2);
    
    fp2 = fopen("trash2.txt","r");
    
    count = 0;
   
    while( (value = getc(fp2)) != EOF )
    {
        
        count++;

        if( count == 8 )
        {
            
            count = 0 ;
            fprintf(fp3,"%c ",value);
            
        }
        
        else
        fprintf(fp3,"%c",value);
        
    }
  
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    
    return x;
    
    
}



void compression( int x )                                                                                        // Compression Function
{
    
    int n , i , j , count , length , no , digit , c = 0;
    int sum = 0;
    FILE *fp1 , *fp2;
    char ch;
    
    fp1 = fopen("savebinary.txt","r");
    fp2 = fopen("zip.txt","w");
    
    if( fp1 == NULL )                                                                                   // Checking If File Is Empty
    {
        
        printf("\n\nFILE NOT FOUND ( BINARY FILE )!!\n\n\n");
        exit(1);
        
    }
    

    do
    {
        
        if( fscanf(fp1,"%d",&n) != EOF ){
          c++;
            
        digit = n;
      
        length = 0;
            
        while( n != 0 )
        {
            
            n = n / 10;
            length++;
        
        }
       
        j = 0;
        no = 0;
        sum = 0;
        
        for( i = length - 1 ; i >= 0 ; i-- )
        {

            no = digit % 10;
            digit = digit/10;
        
            sum = sum + pow(2,j) * (no);
            j++;
            
        }
     
        fprintf(fp2,"%d",sum);
            
        }
        
        else
            break;
        
        
    }while( c != x );
    

    fclose(fp1);
    fclose(fp2);

    
}



void compression_factor()
{
    
    float count_i = 0 , count_o = 0 , factor;
    FILE *fp1 , *fp2;
    char ch , c;
    
    fp1 = fopen("input.txt","r");
    fp2 = fopen("zip.txt","r");
    
    while( (ch = getc(fp1) != EOF) )
        count_i++;
    
    while( (c = getc(fp2) != EOF) )
        count_o++;

    factor = (count_i / count_o);
    
    printf("COMPRESSION FACTOR : %.3f ( TIMES )\n\n\n\n",factor);
    
    fclose(fp1);
    fclose(fp2);
    
    
}



void tree_height()
{
    
    FILE *fp;
    int max = 0 , i = 1;
    char ch;
    
    fp = fopen("binary.txt","r");
    
    while( (ch = getc(fp)) != EOF )
    {
        
        i++;
        
        if( (int)ch == 10 )
        {
            
            if( max< i )
                max = i;
            
            i = 0;
            
        }
        
    }
    
    printf("HEIGHT OF TREE : %d\n\n\n\n",max);
    
    fclose(fp);
    
    
}




int main()
{
    
    int size = 0 , x;
    tree *parent;
    
    start_1D = freq_calculation();

    for( temp_1D = start_1D ; temp_1D != NULL ; temp_1D = temp_1D->next )
    size++;
    
    start_k = generating_k( size );

    start_1D = shell_sort( start_1D , start_k , size );
    
    huffman_tree( start_1D , size );
    
    array *binary = (array*) malloc ( sizeof(array) * size );

    metadata( binary );

    x = save_binary( binary , size );
    
    compression( x );
  
    compression_factor();
    
    tree_height();

    free(binary);
    
    return 0;


}