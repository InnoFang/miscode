package com.example.blog.domain;

import com.example.blog.utils.TagSerialize;
import com.fasterxml.jackson.annotation.*;
import com.fasterxml.jackson.databind.annotation.JsonSerialize;

import javax.persistence.*;
import java.util.Set;

/**
 * Created by Inno Fang on 2018/4/25.
 */
@Entity
//@NamedNativeQuery(
//        name = "Tag.articles",
//        query = "SELECT * FROM tag, article_tag WHERE article_tag.article_id=tag.id")
@JsonSerialize(using = TagSerialize.class)
public class Tag {

    @Id
    @GeneratedValue
    @JsonIgnore
    private Long  id;
    private String name;

    @JsonIgnore
    @ManyToMany
    @JoinTable(name = "article_tag",
            joinColumns = @JoinColumn(name = "tag_id"),
            inverseJoinColumns = @JoinColumn(name = "article_id"))
    private Set<Article> articles;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Set<Article> getArticles() {
        return articles;
    }

    public void setArticles(Set<Article> articles) {
        this.articles = articles;
    }

    @Override
    public String toString() {
        return "Tag{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", articles=" + articles +
                '}';
    }
}
