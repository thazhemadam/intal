//PES2201800014
//Anant Thazhemadam
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int to_integer(char ch)
{
    return (int)(ch - 48);
}

static char to_character(int in)
{
    return (char)(in + 48);
}

char *intal_add(const char *intal1, const char *intal2)
{
    int lengthIntal1 = strlen(intal1);
    int lengthIntal2 = strlen(intal2);

    //Larger and Smaller Length
    int bigLen = (lengthIntal1 > lengthIntal2) ? lengthIntal1 + 1 : lengthIntal2 + 1;
    int smallLen = (lengthIntal1 > lengthIntal2) ? lengthIntal2 : lengthIntal1;

    int i, digit1, digit2, resultDigit, carry = 0;
    //Result is accomodated to be one greater the size of the greater value.
    char *result = (char *)malloc((bigLen + 1) * sizeof(char));

    //Adding digits in the smaller intal to the corresponding digits in the larger intal.
    for (i = 0; i < smallLen; i++)
    {
        digit1 = to_integer(intal1[lengthIntal1 - 1 - i]);
        digit2 = to_integer(intal2[lengthIntal2 - 1 - i]);
        //Calculating sum of the last elements in the intals; similar to how it would be done manually.
        //Handling carry.
        resultDigit = digit1 + digit2 + carry;
        if (resultDigit > 9)
        {
            carry = 1;
            resultDigit = resultDigit - 10;
        }
        else
        {
            carry = 0;
        }
        //Updating the result
        result[bigLen - 1 - i] = to_character(resultDigit);
    }

    //Taking into consideration the elements of the larger intal that haven't been reflected yet in the result.
    while (i < bigLen - 1)
    {
        if (lengthIntal1 > lengthIntal2)
        {
            resultDigit = to_integer(intal1[lengthIntal1 - 1 - i]) + carry;
            if (resultDigit > 9)
            {
                carry = 1;
                resultDigit = resultDigit - 10;
            }
            else
            {
                carry = 0;
            }

            result[bigLen - 1 - i] = to_character(resultDigit);
        }
        else
        {
            resultDigit = to_integer(intal2[lengthIntal2 - 1 - i]) + carry;
            if (resultDigit > 9)
            {
                carry = 1;
                resultDigit = resultDigit - 10;
            }
            else
            {
                carry = 0;
            }
            result[bigLen - 1 - i] = to_character(resultDigit);
        }
        i++;
    }
    //If there still exists a final carry, then the carry value is appended to the beginning of the result, and the result is made to be null terminated.
    if (carry != 0)
    {
        result[0] = to_character(carry);
        result[bigLen] = '\0';
    }
    //If there exists no final carry.
    //Since result was allocated keeping in mind the possibility for a final carry, it was set to have a size one greater than the larger length.
    //However, if there is no carry, then this space that can accomodate one character is wasted and may result in an invalid/undesirable result.
    //Thus, each element is shifted by one to the left, in the array; the memory is reallocated, and the result is made to be null terminated.
    else
    {
        for (i = 0; i < bigLen - 1; i++)
        {
            result[i] = result[i + 1];
        }

        result = (char *)realloc(result, bigLen * sizeof(char));
        result[bigLen - 1] = '\0';
    }
    return result;
}

int intal_compare(const char *intal1, const char *intal2)
{
    int lengthIntal1 = strlen(intal1);
    int lengthIntal2 = strlen(intal2);

    //Unequal lengths
    if (lengthIntal1 > lengthIntal2) //If intal1 is larger than intal2
    {
        return 1;
    }
    else if (lengthIntal2 > lengthIntal1) //If intal2 is larger than intal1
    {
        return -1;
    }

    //Equal lengths
    //Compare each element, from the positions of higher place value.
    for (int i = 0; i < lengthIntal1; i++)
    {
        if (intal1[i] > intal2[i]) //intal1 has a larger digit in a position of greater place value than intal2
        {
            return 1;
        }
        else if (intal2[i] > intal1[i]) //intal2 has a larger digit in a position of greater place value than intal1
        {
            return -1;
        }
    }

    //The lengths are equal as well, and all the elements in all the positions of place value are the same as well.
    //Both intals are equal.
    return 0;
}

char *intal_diff(const char *intal1, const char *intal2)
{
    int comparison = intal_compare(intal1, intal2);
    //Both intal1, intal2 are equal.
    if (comparison == 0)
    {
        char *result = (char *)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    //The intals are unequal, but intal2 is greater than intal1.
    else if (comparison == -1)
    {
        const char *temp = intal1;
        intal1 = intal2;
        intal2 = temp;
    }

    //intal1 is the greater intal.
    //intal2 is the smaller intal.

    int lengthIntal1 = strlen(intal1);
    int lengthIntal2 = strlen(intal2);

    int bigLen = lengthIntal1;
    int smallLen = lengthIntal2;

    int i, digit1, digit2, resultDigit, borrow = 0;

    char *result = (char *)malloc((bigLen + 1) * sizeof(char));

    for (i = 0; i < smallLen; i++)
    {
        digit1 = to_integer(intal1[lengthIntal1 - 1 - i]) - borrow;
        digit2 = to_integer(intal2[lengthIntal2 - 1 - i]);
        //Subtrahend digit is greater than minuend digit
        if (digit2 > digit1)
        {
            borrow = 1;
            digit1 = digit1 + 10;
        }
        else
        {
            borrow = 0;
        }

        resultDigit = digit1 - digit2;

        result[bigLen - 1 - i] = to_character(resultDigit);
    }

    //Remaining numbers in minuend (if any)
    while (i < bigLen)
    {
        resultDigit = to_integer(intal1[lengthIntal1 - 1 - i]) - borrow;
        if (digit2 > digit1)
        {
            borrow = 1;
            digit1 = digit1 + 10;
        }
        else
        {
            borrow = 0;
        }
        result[bigLen - 1 - i] = to_character(resultDigit);

        i++;
    }

    //Trim leading zeros
    for (i = 0; i < bigLen; i++)
    {
        if (result[i] != '0')
            break;
    }

    result[bigLen] = '\0';
    int trim = i;
    if (trim != 0)
    {
        for (i = 0; i <= bigLen - trim; i++)
            result[i] = result[i + trim];

        result = realloc(result, (bigLen - trim + 1) * sizeof(char));
    }

    return result;
}

char *intal_multiply(const char *intal1, const char *intal2)
{

    if (strcmp(intal1, "0") == 0 || strcmp(intal2, "0") == 0)
    {
        char *result = (char *)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int lengthIntal1 = strlen(intal1);
    int lengthIntal2 = strlen(intal2);
    int totalLength = lengthIntal1 + lengthIntal2;
    int i, j, resultDigit, carry = 0;

    char *result = (char *)malloc((totalLength + 2) * sizeof(char));

    for (i = 0; i < totalLength; i++)
        result[i] = '0';

    for (i = 0; i < lengthIntal1; i++)
    {
        carry = 0;
        for (j = 0; j < lengthIntal2; j++)
        {
            int digit1 = to_integer(intal1[lengthIntal1 - 1 - i]);
            int digit2 = to_integer(intal2[lengthIntal2 - 1 - j]);
            int digit3 = to_integer(result[totalLength - 1 - i - j]);

            resultDigit = (digit1 * digit2) + carry + digit3;
            carry = resultDigit / 10;
            resultDigit = resultDigit % 10;

            result[totalLength - 1 - i - j] = to_character(resultDigit);
        }

        for (j = lengthIntal2 + i; j < lengthIntal2 + lengthIntal1; j++)
        {
            int d3 = to_integer(result[totalLength - 1 - j]);

            resultDigit = carry + d3;
            carry = resultDigit / 10;
            resultDigit = resultDigit % 10;
            result[totalLength - 1 - j] = to_character(resultDigit);
        }
    }

    result[totalLength] = '\0';
    if (result[0] == '0')
    {
        for (i = 0; i <= totalLength; i++)
            result[i] = result[i + 1];

        char *temp = realloc(result, totalLength * sizeof(char));
        if (temp != NULL)
        {
            result = temp;
        }
    }

    return result;
}

char *intal_mod(const char *intal1, const char *intal2)
{
    int comparison = intal_compare(intal1, intal2);
    //intal1 is lesser than intal2
    if (comparison == -1)
    {
        char *result = (char *)malloc((strlen(intal1) + 1) * sizeof(char));
        strcpy(result, intal1);
        return result;
    }
    //intals are both equal
    else if (comparison == 0)
    {
        char *result = (char *)malloc((2) * sizeof(char));
        strcpy(result, "0");
        return result;
    }

    int p = strlen(intal2);
    int stop = strlen(intal1);
    char *intermediate = (char *)malloc((strlen(intal2) + 2) * sizeof(char));
    for (int i = 0; i < p; i++)
        intermediate[i] = intal1[i];
    intermediate[p] = '\0';

    do
    {
        //when intermediate dividend is lesser than intal2; bring down one number from dividend (intal1) to the append to the end of intermediate dividend
        if (intal_compare(intermediate, intal2) == -1 && p < stop)
        {
            int len = strlen(intermediate);
            if (strcmp(intermediate, "0") == 0)
                len = 0;
            intermediate[len] = intal1[p];
            intermediate[len + 1] = '\0';
            p++;
        }
        //When intal2 is not greater than intermediate dividend, keep reducing intal2 from it.
        if (intal_compare(intermediate, intal2) != -1)
        {
            char *result = intal_diff(intermediate, intal2);
            while (intal_compare(result, intal2) > -1)
            {
                char *temp = result;
                result = intal_diff(result, intal2);
                free(temp);
            }

            strcpy(intermediate, result);
            free(result);
        }
    } while (p < stop);

    intermediate = realloc(intermediate, (strlen(intermediate) + 2) * sizeof(char));
    intermediate[strlen(intermediate) + 1] = '\0';
    return intermediate;
}

char *intal_pow(const char *intal1, unsigned int n)
{

    char *result = malloc(sizeof(char) * 2);
    result[0] = '1';
    result[1] = '\0';

    int intal1length = strlen(intal1);
    char *newcopy = malloc(sizeof(char) * intal1length + 1);
    
    strcpy(newcopy, intal1);
    char *zero = malloc(sizeof(char) * 2);
    strcpy(zero, "0");
    if (intal1 == zero)
    {
        char *temp1 = malloc(sizeof(char) * 2);
        temp1[0] = '0';
        temp1[1] = '\0';
        return temp1;
    }
    if (n == 0)
    {
        char *temp = malloc(sizeof(char) * 2);
        temp[0] = '1';
        temp[1] = '\0';
        return temp;
    }
    while (n > 0)
    {
        if (n % 2)
        {
            char *arg = result;
            result = intal_multiply(result, newcopy);
            free(arg);
            n--;
        }
        else
        {
            char *arg = newcopy;
            newcopy = intal_multiply(newcopy, newcopy);
            free(arg);
            n = n / 2;
        }
    }
    free(newcopy);
    free(zero);
    return result;
}

char *intal_gcd(const char *intal1, const char *intal2)
{

    //If one of the digits is 0, hcf is the other digit
    if (intal_compare(intal1, "0") == 0)
    {
        // printf("Intal1 is 0\n");
        char *b = (char *)malloc((strlen(intal2) + 1) * sizeof(char));
        strcpy(b, intal2);
        b[strlen(intal2)] = '\0';
        return b;
    }

    if (intal_compare(intal2, "0") == 0)
    {
        char *b = (char *)malloc((strlen(intal1) + 1) * sizeof(char));
        strcpy(b, intal1);
        b[strlen(intal1)] = '\0';
        return b;
    }

    char *a = (char *)malloc((strlen(intal1) + 1) * sizeof(char));
    strcpy(a, intal1);
    char *b = (char *)malloc((strlen(intal2) + 1) * sizeof(char));
    strcpy(b, intal2);

    int flag = strcmp(a, "0");
    //until a = 0
    while (flag != 0)
    {
        char *temp = b;         //temp = b
        b = a;                  //b = a
        a = intal_mod(temp, a); //a = b%a

        free(temp);
        flag = strcmp(a, "0"); //flag for checking if a = 0
    }

    free(a);
    return b;
}

char *intal_fibonacci(unsigned int n)
{
    char *a = (char *)malloc(2 * sizeof(char));
    //Fibonacci(0) = 1
    a[0] = '0';
    a[1] = '\0';
    //Fibonacci(0) = 1
    if (n == 0)
        return a;

    ////Fibonacci(1) = 1
    char *b = (char *)malloc(2 * sizeof(char));
    b[0] = '1';
    b[1] = '\0';
    //Fibonacci(1) = 1
    if (n == 1)
        return b;

    for (int i = 1; i < n; i++)
    {
        char *c = intal_add(a, b); // Fibonacci(i) = Fibonacci(i-2) + Fibonacci(i-1)
        free(a);
        a = b;
        b = c;
    }

    free(a);
    return b;
}

char *intal_factorial(unsigned int n)
{
    //Factorial(0) = 1
    char *start = (char *)malloc(2 * sizeof(char));
    start[0] = '1';
    start[1] = '\0';
    //Factorial(0) = 1
    //Factorial(1) = 1
    if (n < 2)
        return start;

    //Final result is initialized to be 1.
    char *result = (char *)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';

    //Each step = 1.
    char *step = (char *)malloc(2 * sizeof(char));
    step[0] = '1';
    step[1] = '\0';

    for (int i = 1; i < n; i++)
    {
        char *temp = start; //For freeing the previous older start in memory
        //For each iteration till n, start is incremented by one.
        start = intal_add(start, step);
        free(temp);

        temp = result; //For freeing the previous older result in memory
        //Result = Result*Start
        result = intal_multiply(start, result);
        free(temp);
    }

    free(start);
    free(step);

    return result;
}

char *intal_bincoeff(unsigned int n, unsigned int k)
{
    if(n==0)
    {
        char*g=malloc(sizeof(char)*2);
        g[0]='0';
        g[1]='\0';
        return g;
    }
    if(k==0){
        char*g=malloc(sizeof(char)*2);
        g[0]='1';
        g[1]='\0';
        return g;
    }  

    if(k > n-k)
    {
        	k=n-k;
    }
    char **c = (char **)malloc((k + 1) * sizeof(char *));
    
    char *myzero=(char*)malloc(sizeof(char)*2);
    myzero[0]='0';
    myzero[1]='\0';


    for (int i = 0; i < k + 1; i++)
    {
        c[i] = (char *)malloc(2 * sizeof(char));
        strcpy(c[i],myzero);
    
    }
    
    c[0][0] = '1';


    for (int i = 1; i < n + 1; i++)
    {
        int j = (i > k) ? k : i;
        while (j > 0)
        {
            char *temp = c[j];
            c[j] = intal_add(c[j], c[j - 1]);
            free(temp);
            j--;
        }
    }

    char *result = (char *)malloc((strlen(c[k]) + 1) * sizeof(char));
    strcpy(result, c[k]);

    for (int i = 0; i < k + 1; i++)
    {
        free(c[i]);
    }
    free(c);
    free(myzero);
    return result;
}


int intal_max(char **arr, int n)
{
    int max = 0;

    for (int i = 1; i < n; i++)
    {
        if (intal_compare(arr[max], arr[i]) == -1)
        {
            max = i;
        }
    }

    return max;
}

int intal_min(char **arr, int n)
{
    int min = 0;

    for (int i = 1; i < n; i++)
    {
        if (intal_compare(arr[min], arr[i]) == 1)
        {
            min = i;
        }
    }

    return min;
}

int intal_binsearch(char **arr, int n, const char *key)
{
    int answer = -1;
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (intal_compare(arr[mid], key) == -1)
        {
            low = mid + 1;
        }
        else if (intal_compare(arr[mid], key) == 1)
        {
            high = mid - 1;
        }
        else if (intal_compare(arr[mid], key) == 0)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            continue;
        }
    }
    return answer;
}

int partition(char **arr, int l, int pivotLocation)
{
    int i = l - 1;
    char *pivot = arr[pivotLocation];

    for (int j = l; j < pivotLocation; j++)
    {
        if (intal_compare(arr[j], pivot) < 0)
        {
            i++;
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    char *temp = arr[i + 1];
    arr[i + 1] = arr[pivotLocation];
    arr[pivotLocation] = temp;

    return (i + 1);
}

void quicksort(char **arr, int l, int h)
{
    if (l < h)
    {
        int partitionIndex = partition(arr, l, h);
        quicksort(arr, l, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, h);
    }
}

void intal_sort(char **arr, int n)
{
    quicksort(arr, 0, n - 1);
}

int intal_search(char **arr, int n, const char *key)
{

    int found = -1;

    for (int i = 0; i < n; i++)
    {
        if (intal_compare(arr[i], (char *)key) == 0)
        {
            found = i;
            break;
        }
    }

    return found;
}

char *coin_row_problem(char **arr, int n)
{
	if(n ==0)
	{
		return "0";
 	}
    char *previous = "0";
    char *current = arr[0];
    char *next = NULL;
	int i;
    char *temp = NULL;
    // char *tempTracker = NULL;
    for(i=2; i<=n; i++)
	{
        // if(tempTracker!=NULL && tempTracker!= current && tempTracker!=previous){
        //     free(tempTracker);
        //     tempTracker = NULL;
        // }
    	char *arrvalue=arr[i-1];
        temp=intal_add(previous,arrvalue);
        int value=intal_compare(temp,current);
        if(value==1)
	    {
        	next=temp;
        }
        else
	 	{
            next=current;
            free(temp);
        }
        previous=current;
        current=next;
        // if(tempTracker==NULL){
        //     tempTracker= temp;
        // }
    }
    // if(tempTracker!=NULL){
    //     free(tempTracker);
    // }
    
    
    char *result = (char *) malloc(sizeof(char)*(strlen(current)+1));
    strcpy(result,current);
    free(current);
	return result;
}
