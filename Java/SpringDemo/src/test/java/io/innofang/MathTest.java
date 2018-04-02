package io.innofang;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/3/29.
 */
public class MathTest {

    @Before
    public void setup() throws Exception {

    }

    @Test
    public void factorial() throws Exception {
        assertEquals(120, new Math().factorial(5));
    }

}