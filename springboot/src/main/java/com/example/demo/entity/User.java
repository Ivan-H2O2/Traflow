package com.example.demo.entity;

import java.io.Serializable;

/**
 * 用户信息表(User)实体类
 *
 * @author makejava
 * @since 2023-01-27 18:10:21
 */
public class User implements Serializable {
    private static final long serialVersionUID = 264850498646961711L;
    /**
     * ID
     */
    private Integer id;
    /**
     * username
     */
    private String username;
    /**
     * password
     */
    private String password;

    private String nickName;

    private Integer age;

    private String sex;

    private String address;


    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getNickName() {
        return nickName;
    }

    public void setNickName(String nickName) {
        this.nickName = nickName;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

}

