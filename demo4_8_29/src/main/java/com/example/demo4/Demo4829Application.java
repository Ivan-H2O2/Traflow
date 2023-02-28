package com.example.demo4;


import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("com.example.demo4.mapper")
public class Demo4829Application {

    public static void main(String[] args) {
        SpringApplication.run(Demo4829Application.class, args);
    }

}
