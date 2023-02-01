package com.example.demo4.controller;


import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

@RestController
@RequestMapping("/user")//和前端的接口相呼应
public class UserController {
    @Resource
    private UserMapper userMapper;

    @ResponseBody
    @GetMapping("/info")
    public Result<User> save(@RequestBody User user) {
        if(user.getPassword() == null){
            user.setPassword("123456");
        }
        userMapper.insert(user);
        return Result.success();
    }
    @GetMapping
//    分页查询 MyBatis插件
    public Result<User> findPage(@RequestParam Integer pageNum, @RequestParam Integer pageSize, @RequestParam String search ) {
//    分页模糊查询mybatis-plus
        Page<User> userPage = userMapper.selectPage(new Page<>(pageNum, pageSize), Wrappers.<User>lambdaQuery().like(User::getNickName, search));
        return Result.success();
    }