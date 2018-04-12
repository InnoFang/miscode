/**
 * Created by InnF on 2018/4/12.
 */

import React from 'react';
import {Row, Col} from 'antd';

export default class PCFooter extends React.Component {

    render() {
        return (
            <footer>
                <Row>
                    <Col span={2}/>
                    <Col span={20} id="footer">
                        &copy;&nbsp;2018 ReactNews. All Rights Reserved.
                    </Col>
                    <Col span={2}/>
                </Row>
            </footer>
        );
    };
}
