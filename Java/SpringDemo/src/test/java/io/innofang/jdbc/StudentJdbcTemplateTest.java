package io.innofang.jdbc;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.List;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class StudentJdbcTemplateTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-jdbc.xml");
        StudentJdbcTemplate sjt =   (StudentJdbcTemplate) context.getBean("student_jdbc_template");

        System.out.println("------Records Creation------");
        sjt.create("Zara", 11);
        sjt.create("Nuha", 2);
        sjt.create("Ayan", 15);

        System.out.println("------Listing Multiple Records------");
        List<Student> students = sjt.listStudents();
        for (Student student : students) {
            System.out.print("ID: " + student.getId());
            System.out.print(", Name: " + student.getName());
            System.out.println(", Age: " + student.getAge());
        }
        System.out.println("------Updating Record with ID = 2------");
        sjt.update(2, 20);

        System.out.println("------Listing Record with ID = 2------");
        Student student = sjt.getStudent(2);
        System.out.print("ID: " + student.getId());
        System.out.print(", Name: " + student.getName());
        System.out.print(", Age: " + student.getAge());
    }

}