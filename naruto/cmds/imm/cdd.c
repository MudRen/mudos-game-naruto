// cd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object env;
        string file,dir;
        int last;
        
        env = environment(me);
        file = base_name(env);
        last = strsrch( file,"/",-1);
        dir = file[0..last];
        me->set("cwd", dir);
        write(dir + "\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : cdd

將目前參考的目錄移至目前所在地檔案的目錄。
HELP
        );
        return 1;
}
