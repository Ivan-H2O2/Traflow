package com.example.demo4.repository;


import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class BookRepositoryTest {

    @Autowired
    private BookRepository bookRepository;

    @Test
    void findAll(){
        System.out.println(bookRepository.findAll());
    }
}
//————————————————
//        版权声明：本文为CSDN博主「今天又有什么bug」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//        原文链接：https://blog.csdn.net/weixin_46019681/article/details/124905877