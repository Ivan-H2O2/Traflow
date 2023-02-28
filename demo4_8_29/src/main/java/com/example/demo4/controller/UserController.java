package com.example.demo4.controller;


import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.example.demo4.common.Result;
import com.example.demo4.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import com.example.demo4.mapper.UserMapper;
import javax.annotation.Resource;

@RestController
@ResponseBody
@RequestMapping("/user")//和前端的接口相呼应
public class UserController {
    @Resource
    @Autowired
    private UserMapper userMapper;

    @PostMapping// 代表前端axios使用post方法
    public Result<?> save(@RequestBody User user) {
        if (user.getPassword() == null) {
            user.setPassword("123456");
        }
        userMapper.insert(user);// 把前端传过来的数据插入数据库里
        return Result.success();
    }

    @PutMapping// 更新
    public Result<?> update(@RequestBody User user) {
        userMapper.updateById(user);
        return Result.success();
    }
    @DeleteMapping ("/{id}")// 删除
    public Result<?> delete(@PathVariable Long id) {
        userMapper.deleteById(id);
        return Result.success();
    }

    @GetMapping// get方法
//    分页查询 MyBatis插件
//    默认查询值（在不加参数的情况下）
    public Result<?> findPage(@RequestParam(defaultValue = "1") Integer pageNum,
                              @RequestParam(defaultValue = "10") Integer pageSize,
                              @RequestParam(defaultValue = "") String search) {
//    分页模糊(like)查询mybatis-plus
        LambdaQueryWrapper<User> wrapper = Wrappers.<User>lambdaQuery();
//     使用hutool工具类，如果nickname为不空才启动模糊查询
        if (StrUtil.isNotBlank(search)) {
            wrapper.like(User::getNickName, search);
        }
        Page<User> userPage = userMapper.selectPage(new Page<>(pageNum, pageSize), wrapper);
        return Result.success(userPage);
    }

}