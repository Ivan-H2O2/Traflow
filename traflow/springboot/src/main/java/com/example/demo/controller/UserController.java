package com.example.demo.controller;

import com.example.demo.common.Result;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

// 用来返回json
@RestController
//定义路由 user是接口统一的路由
@RequestMapping("/user")
public class UserController {

    // Post 接口
    @PostMapping
    public Result save() {

    }
}
