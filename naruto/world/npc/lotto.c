/* lotto.c
   樂透 三十八號選六號 摸彩程式
   write by -Acme-
*/

#include <localtime.h>
#include <npc.h>

inherit F_VILLAGER;

// 每張樂透單價(price), 賣出總量(amount), 是否正在開獎(lottery)
// 得獎號碼(award), 暫存用變數(temp)
int price = 50, amount = 0, lottery = 0, *award, *temp;

// 總獎金是當期總投注金額乘以總獎金率得之, 總獎金率(total_ratio)
// 總獎金減掉普獎總額後，依下列比率分配獎金
// 頭獎(first_ratio), 二獎(second_ratio), 三獎(third_ratio), 四獎(fourth_ratio)
int total_ratio = 58, first_ratio = 38, second_ratio = 12, third_ratio = 15, fourth_ratio = 35;

// 號碼陣列(numbers)
int *numbers = ({  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                  31, 32, 33, 34, 35, 36, 37, 38 });

// 購買記錄(record), 得獎記錄(prize)
mapping record = ([]);
mapping prize = ([]);

void do_lottery();

void create()
{
    set_name("樂透美眉", ({ "lotto girl", "girl" }));
    set_race("human");
    set_level(1);

    set("age", 18);
    set("title", "爽歪歪");
    set("gender", "female");
    set("nickname", "包中");
    set("long", "一位穿著火辣的美眉令人垂涎欲滴。\n");

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

// 亂數取6個號碼
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

// 撿查號碼是否有重複
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

// 加入一筆號碼
void add_bet(string id, int *nums)
{
    if( undefinedp(record[id]) ) record[id] = ({});
    record[id] += ({ nums });
    amount++;
}

int do_bet(string arg)
{
    int t, *nums = ({0,0,0,0,0,0});

    // 在區域中，同一格座標才會有作用
    if( environment(this_object())->is_area() )
        if( !area_environment(this_object(), this_player()) ) return 0;

    if( !arg ) return notify_fail("請輸入 help lotto 了解如何玩樂透遊戲。\n");

    if( arg == "random") {
        if( this_player()->query("bank") < price )
            return notify_fail("你銀行不夠錢，無法買彩券。\n");
        this_player()->add("bank", -price);
        nums = do_random(6);
        add_bet(this_player()->query_id(), nums);

    } else if( sscanf(arg, "random %d", t) == 1 ) {
        string id;
        if( t <= 0 || t >= 100 ) return notify_fail("請輸入 help lotto 了解如何玩樂透遊戲。\n");
        if( this_player()->query("bank") < price*t )
            return notify_fail("你銀行不夠錢，無法買彩券。\n");
        this_player()->add("bank", -(price*t));
        id = this_player()->query_id();
        while( t-- ) {
            nums = do_random(6);
            add_bet(id, nums);
        }

    } else if( sscanf(arg, "%d %d %d %d %d %d", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]) == 6 ) {
        if( !check_number(nums) ) return notify_fail("請輸入 help lotto 了解如何玩樂透遊戲。\n"); 
        if( this_player()->query("bank") < price )
            return notify_fail("你銀行不夠錢，無法買彩券。\n");
        this_player()->add("bank", -price);
        add_bet(this_player()->query_id(), nums);

    } else return notify_fail("請輸入 help lotto 了解如何玩樂透遊戲。\n"); 

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

// 開獎
void do_lottery()
{
    int sp_number;

    if( !lottery ) return;
    
    // 亂數取七個不重複號碼，一個為特別號
    award = do_random(7);

    // 特別號需要另外處理
    sp_number = award[6];
    award -= ({ award[6] });
}