package com.example.demo.repository;
import com.example.demo.entity.Book;
import org.springframework.data.jpa.repository.JpaRepository;


public interface BookRepository extends JpaRepository<Book,Integer>{
}
