package cn.edu.bupt.mybatis.demo.todo;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@MapperScan("cn.edu.bupt.mybatis.demo.todo.mybatis.mapper")
@SpringBootApplication
public class MybatisDemoTodoApplication {

    public static void main(String[] args) {
        SpringApplication.run(MybatisDemoTodoApplication.class, args);
    }

}
