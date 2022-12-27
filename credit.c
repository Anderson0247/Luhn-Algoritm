#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50
#include <math.h>

int main(void) 
{

    long cardnumber;

    do
    {
        cardnumber = get_long("Digite o número do cartão: \n");
    }
    while (cardnumber < 0);

    long digitcount = cardnumber;
    int digitqty = 0;
    int somadnm = 0;
    int somadp = 0;
    int firstd;
    string card = "INVALID";
    int flag;

// Obtenção da quantidade de digitos no cartao

    while (digitcount > 0)
    {
        digitqty++;
        digitcount = digitcount / 10;
    }

// Obtenção dos primeiros 2 digitos do cartão

    if (digitqty == 13)
    {
        firstd = cardnumber / 100000000000;
    }
    else if (digitqty == 15)
    {
        firstd = cardnumber / 10000000000000;
    }
    else if (digitqty == 16)
    {
        firstd = cardnumber / 100000000000000;
    }
    else
    {
        firstd = 0;
    }

// checksum de LUHN

    for (int i = 1; i <= digitqty; i++)
    {
        if (i % 2 != 0)
        {
            somadnm += cardnumber % 10;
            cardnumber = cardnumber / 10;
        }
        if (i % 2 == 0)
        {
            flag = cardnumber % 10 * 2;
            if (flag >= 10)
            {
                somadp += flag / 10;
                somadp += flag % 10;
            }
            else
            {
                somadp += flag;
            }
            cardnumber = cardnumber / 10;
        }
    }

    int somatotal = somadnm + somadp;
    
//Obtenção da Empresa dona do cartao, se o mesmo for válido
    
    if (somatotal % 10 == 0 && ((digitqty == 13) || (digitqty == 15) || (digitqty == 16)))
    {
        if (digitqty >= 13 && digitqty <= 16)
        {
            if (digitqty == 15 && (firstd == 34 || firstd == 37))
            {
                card = "AMEX";
            }
            else if (digitqty == 16 && (firstd == 51 || firstd == 52 || firstd == 53 || firstd == 54 || firstd == 55))
            {
                card = "MASTERCARD";
            }
            else if ((digitqty == 13 || digitqty == 16) && (firstd == 40 || firstd == 41 || firstd == 42 || firstd == 43 || firstd == 44
                     || firstd == 45 || firstd == 46 || firstd == 47 || firstd == 48 || firstd == 49))
            {
                card = "VISA";
            }
        }
        else
        {
            card = "INVALID";
        }

    }
    else
    {
        card = "INVALID";
    }

    printf("%s\n", card);

}