function y = gen_wave( tone, rythm ) 
    Fs = 8192;
    freqs = [523, 587, 659, 698, 783, 880, 988];
    x = linspace(0, 2 * pi * rythm, floor(Fs * rythm));
    y = sin(freqs(tone) * x) .* (1 - x / (rythm * 2 * pi));
end

