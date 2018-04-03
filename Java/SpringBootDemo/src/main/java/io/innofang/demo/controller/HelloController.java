package io.innofang.demo.controller;

import io.innofang.demo.properties.GirlProperties;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

/**
 * Created by Inno Fang on 2018/4/2.
 */
// @RestController = @Controller + @ResponseBody
@Controller
@ResponseBody
@RequestMapping(value = {"/hello", "/hi", "/girl"})
public class HelloController {

    @Autowired
    private GirlProperties girl;

    @RequestMapping(value = "/say/{id}", method = RequestMethod.GET)
    public String say(@PathVariable("id") Integer id) {
        return "ID:" + id
                + "\n" + girl.toString();
    }

//    @RequestMapping(value = "/ask", method = RequestMethod.GET)
    @GetMapping(value = "/ask")
    public String ask(@RequestParam(value = "id", required = false, defaultValue = "0") int i) {
        return "ID: " + i;
    }
}
