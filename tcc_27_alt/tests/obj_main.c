int printf(const char *, ...);
int obj_value(void);

int main(void)
{
    printf("object link %d\n", obj_value() + 25);
    return 0;
}
