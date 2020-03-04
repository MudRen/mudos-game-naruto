/* lotto.c
   �ֳz �T�Q�K���碌�� �N�m�{��
   write by -Acme-
*/

#include <localtime.h>
#include <npc.h>

inherit F_VILLAGER;

// �C�i�ֳz���(price), ��X�`�q(amount), �O�_���b�}��(lottery)
// �o�����X(award), �Ȧs���ܼ�(temp)
int price = 50, amount = 0, lottery = 0, *award, *temp;

// �`�����O����`��`���B���H�`�����v�o��, �`�����v(total_ratio)
// �`����������`�B��A�̤U�C��v���t����
// �Y��(first_ratio), �G��(second_ratio), �T��(third_ratio), �|��(fourth_ratio)
int total_ratio = 58, first_ratio = 38, second_ratio = 12, third_ratio = 15, fourth_ratio = 35;

// ���X�}�C(numbers)
int *numbers = ({  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                  31, 32, 33, 34, 35, 36, 37, 38 });

// �ʶR�O��(record), �o���O��(prize)
mapping record = ([]);
mapping prize = ([]);

void do_lottery();

void create()
{
    set_name("�ֳz����", ({ "lotto girl", "girl" }));
    set_race("human");
    set_level(1);

    set("age", 18);
    set("title", "�n�n�n");
    set("gender", "female");
    set("nickname", "�]��");
    set("long", "�@���ۤ��������ܥO�H���C���w�C\n");

    set("chat_chance", 5);
    set("chat_msg", ({
        (: do_lottery :),
    }));

    setup();
}

void init()
{
    add_action("do_bet", "bet");
}

// �üƨ�6�Ӹ��X
int *do_random(int count)
{
    int t, *nums=({});
    temp = numbers;
    while(count--) {
        t = temp[random(sizeof(temp))];
        nums += ({ t });
        temp -= ({ t });
    }
    return nums;
}

// �߬d���X�O�_������
int check_number(int *nums)
{
    int i = sizeof(nums);
    temp = numbers;
    while(i--) {
        if( member_array(nums[i], temp) == -1 ) return 0;
        else temp -= ({ nums[i] });
    }
    return 1;
}

// �[�J�@�����X
void add_bet(string id, int *nums)
{
    if( undefinedp(record[id]) ) record[id] = ({});
    record[id] += ({ nums });
    amount++;
}

int do_bet(string arg)
{
    int t, *nums = ({0,0,0,0,0,0});

    // �b�ϰ줤�A�P�@��y�Ф~�|���@��
    if( environment(this_object())->is_area() )
        if( !area_environment(this_object(), this_player()) ) return 0;

    if( !arg ) return notify_fail("�п�J help lotto �F�Ѧp�󪱼ֳz�C���C\n");

    if( arg == "random") {
        if( this_player()->query("bank") < price )
            return notify_fail("�A�Ȧ椣�����A�L�k�R�m��C\n");
        this_player()->add("bank", -price);
        nums = do_random(6);
        add_bet(this_player()->query_id(), nums);

    } else if( sscanf(arg, "random %d", t) == 1 ) {
        string id;
        if( t <= 0 || t >= 100 ) return notify_fail("�п�J help lotto �F�Ѧp�󪱼ֳz�C���C\n");
        if( this_player()->query("bank") < price*t )
            return notify_fail("�A�Ȧ椣�����A�L�k�R�m��C\n");
        this_player()->add("bank", -(price*t));
        id = this_player()->query_id();
        while( t-- ) {
            nums = do_random(6);
            add_bet(id, nums);
        }

    } else if( sscanf(arg, "%d %d %d %d %d %d", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]) == 6 ) {
        if( !check_number(nums) ) return notify_fail("�п�J help lotto �F�Ѧp�󪱼ֳz�C���C\n"); 
        if( this_player()->query("bank") < price )
            return notify_fail("�A�Ȧ椣�����A�L�k�R�m��C\n");
        this_player()->add("bank", -price);
        add_bet(this_player()->query_id(), nums);

    } else return notify_fail("�п�J help lotto �F�Ѧp�󪱼ֳz�C���C\n"); 

    return 1;
}

int check_hit(int *nums)
{
    int count, size;
    size = sizeof(nums);
    while( size-- ) {
        if( member_array(nums[size], award) != -1 )
            count++;
    }
    return count;
}

// �}��
void do_lottery()
{
    int sp_number;

    if( !lottery ) return;
    
    // �üƨ��C�Ӥ����Ƹ��X�A�@�Ӭ��S�O��
    award = do_random(7);

    // �S�O���ݭn�t�~�B�z
    sp_number = award[6];
    award -= ({ award[6] });
}