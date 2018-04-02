package io.innofang.loosely_coupled;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class OutputHelper {
    IOutputGenerator outputGenerator;

    public void generateOutput() {
        this.outputGenerator.generateOutput();
    }

    public void setOutputGenerator(IOutputGenerator outputGenerator) {
        this.outputGenerator = outputGenerator;
    }
}
