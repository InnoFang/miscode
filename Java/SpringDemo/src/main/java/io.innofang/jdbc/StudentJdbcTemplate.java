package io.innofang.jdbc;

import org.springframework.jdbc.core.JdbcTemplate;

import javax.sql.DataSource;
import java.util.List;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class StudentJdbcTemplate implements StudentDao {

    private DataSource dataSource;
    private JdbcTemplate jdbcTemplate;

    public void setDataSource(DataSource ds) {
        dataSource = ds;
        jdbcTemplate = new JdbcTemplate(ds);
    }

    public void create(String name, Integer age) {
        String sql = "insert into Student (name, age) values(?, ?)";
        jdbcTemplate.update(sql, name, age);
        System.out.println("Created record name=" + name + ", age=" + age);
    }

    public Student getStudent(Integer id) {
        String sql = "select * from student where id=?";
        Student student = jdbcTemplate.queryForObject(sql, new Object[]{id}, new StudentMapper());
        return student;
    }

    public List<Student> listStudents() {
        String sql = "select * from student";
        List<Student> students = jdbcTemplate.query(sql, new StudentMapper());
        return students;
    }

    public void delete(Integer id) {
        String sql = "delete from student where id=?";
        jdbcTemplate.update(sql, id);
        System.out.println("Deleted record with id=" + id);
    }

    public void update(Integer id, Integer age) {
        String sql = "update student set age=? where id=?";
        jdbcTemplate.update(sql, age, id);
        System.out.println("Updated record with id=" + id);
    }
}
