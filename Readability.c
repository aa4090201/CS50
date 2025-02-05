#include <cs50.h>
#include <stdio.h>
#include <string.h>

int letters(string);
int sentence(string);
int word(string);

float calculate(int, int, int);

int grade(float);

int main(void)
{
    string text = get_string("TEXT: ");
    int c = letters(text), sen = sentence(text), w = word(text);

    printf("index = %i,%i,%i\n", c, sen, w);

    float index = calculate(c, w, sen);

    printf("index = %f\n", index);
    grade(index);
}

float calculate(int c, int w, int sen)
{
    float index = 0.0588 * c / w * 100 - 0.296 * sen / w * 100 - 15.8;
    return index;
}
int letters(string text)
{
    int c = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 65 && text[i] <= 122)
        {
            c++;
        }
    }
    return c;
}
int sentence(string text)
{
    int sen = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sen++;
        }
    }
    return sen;
}
int word(string text)
{
    int w = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
    }
    return w;
}

int grade(float index)
{
    int Grade = 0;
    float i = 0;
    if (index <= 1)
    {
        printf("Grade: Before Grade 1 \n");
    }
    else if (index >= 16)
    {
        printf("Grade: 16+\n");
    }
    else
    {
        while (Grade == 0)
        {
            i++;
            if (index < i)
            {
                if (index > (i + i - 1) / 2)
                {
                    Grade = i;
                }
                else
                {
                    Grade = i - 1;
                }
            }
        }
        printf("Grade: %i\n", Grade);
    }

    return 0;
}
