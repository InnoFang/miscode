package com.example.blog.domain;

import com.fasterxml.jackson.annotation.JsonFormat;

import javax.persistence.*;
import java.util.Date;
import java.util.Set;

/**
 * Created by Inno Fang on 2018/4/25.
 */
@Entity
//@NamedNativeQuery(
//        name = "Article.type",
//        query = "SELECT * FROM article, article_tag WHERE article_tag.article_id=article.id")
public class Article {

    @Id
    @GeneratedValue
    private Long id;
    private String src;
    private String title;
    @Column(columnDefinition = "text")
    private String content;
    private String author;
    private Integer readNum;
    private Integer comment;
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    private Date pubTime;
    @ManyToMany
    @JoinTable(name = "article_tag",
            joinColumns = @JoinColumn(name = "article_id"),
            inverseJoinColumns = @JoinColumn(name = "tag_id"))
    private Set<Tag> type;

    public void setId(Long id) {
        this.id = id;
    }

    public String getSrc() {
        return src;
    }

    public void setSrc(String src) {
        this.src = src;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public Integer getReadNum() {
        return readNum;
    }

    public void setReadNum(Integer readNum) {
        this.readNum = readNum;
    }

    public Integer getComment() {
        return comment;
    }

    public void setComment(Integer comment) {
        this.comment = comment;
    }

    public Date getPubTime() {
        return pubTime;
    }

    public void setPubTime(Date pubTime) {
        this.pubTime = pubTime;
    }

    public Long getId() {
        return id;
    }

    public Set<Tag> getType() {
        return type;
    }

    public void setType(Set<Tag> type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return "Article{" +
                "id=" + id +
                ", src='" + src + '\'' +
                ", title='" + title + '\'' +
                ", content='" + content + '\'' +
                ", author='" + author + '\'' +
                ", readNum=" + readNum +
                ", comment=" + comment +
                ", pubTime=" + pubTime +
                ", type=" + type +
                '}';
    }
}
