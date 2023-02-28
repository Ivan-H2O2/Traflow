package com.example.demo4.repository;
import com.example.demo4.entity.Book;
import org.springframework.data.jpa.repository.JpaRepository;


public interface BookRepository extends JpaRepository<Book,Integer>{
}
