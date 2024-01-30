package cn.edu.bupt.ajax.todo.demo;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@MapperScan("cn.edu.bupt.ajax.todo.demo.mapper")
@SpringBootApplication
public class AjaxTodoDemoApplication {

    public static void main(String[] args) {
        SpringApplication.run(AjaxTodoDemoApplication.class, args);
    }

}
