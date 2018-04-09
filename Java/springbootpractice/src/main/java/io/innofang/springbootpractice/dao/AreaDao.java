package io.innofang.springbootpractice.dao;

import io.innofang.springbootpractice.entity.Area;

import java.util.List;

/**
 * Created by Inno Fang on 2018/4/8.
 *
 * dao 层，MyBatis 相关
 */
public interface AreaDao {
    /**
     * 列出区域列表
     *
     * @return areaList
     */
    List<Area> queryArea();

    /**
     * 根据Id列出具体区域
     *
     * @return area
     */
    Area queryAreaById(int areaId);

    /**
     * 插入区域信息
     *
     * @param area
     * @return
     */
    int insertArea(Area area);

    /**
     * 更新区域信息
     *
     * @param area
     * @return
     */
    int updateArea(Area area);

    /**
     * 删除区域信息
     *
     * @param areaId
     * @return
     */
    int deleteArea(int areaId);
}