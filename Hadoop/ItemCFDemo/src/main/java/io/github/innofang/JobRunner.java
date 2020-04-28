package io.github.innofang;

import io.github.innofang.step1.MR1;
import io.github.innofang.step2.MR2;
import io.github.innofang.step3.MR3;
import io.github.innofang.step4.MR4;
import io.github.innofang.step5.MR5;

import java.lang.reflect.InvocationTargetException;
import java.util.stream.Stream;

public class JobRunner {
    public static void main(String[] args) {
        boolean result = Stream.of(MR1.class, MR2.class, MR3.class, MR4.class, MR5.class)
                .allMatch(mrClass -> {
                    System.out.println("Running Job: " + mrClass.getSimpleName());
                    try {
                        return (boolean) mrClass.getMethod("run").invoke(null);
                    } catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
                        e.printStackTrace();
                    }
                    return false;
                });
        if (result) {
            System.out.println("JobRunner run successfully.");
        } else {
            System.out.println("JobRunner run failed.");
        }
    }
}
