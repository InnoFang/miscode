do = gen_wave(1, 0.5);
do_ = gen_wave(1, 1);
re = gen_wave(2, 0.5);
re_ = gen_wave(2, 1);
mi = gen_wave(3, 0.5);
mi_ = gen_wave(3, 1);
fa = gen_wave(4, 0.5);
fa_ = gen_wave(4, 1);
so = gen_wave(5, 0.5);
so_ = gen_wave(5, 1);
la = gen_wave(6, 0.5);
la_ = gen_wave(6, 1);
si = gen_wave(7, 0.5);
si_ = gen_wave(7, 1); 

twinkle_star = [ 
    do, do, so, so, la, la, so_  ...
    ,fa, fa, mi, mi, re, re, do_ ...
    ,so, so, fa, fa, mi, mi, re_ ...
    ,so, so, fa, fa, mi, mi, re_ ...
    ,do, do, so, so, la, la, so_ ...
    ,fa, fa, mi, mi, re, re, do_];

Fs = 8192;
sound(twinkle_star, Fs);