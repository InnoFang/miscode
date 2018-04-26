/**
 * Created by InnF on 2018/4/9.
 */

import React, {Component} from 'react'

class GiphyImage extends Component {
    constructor(props) {
        super(props);

        this.state = {
            giphyUrl: '',
            isLoading: false
        };
    }

    componentDidMount() {
        const giphyApi = '//api.giphy.com/v1/gifs/search?api_key=dc6zaTOxFJmzC&limit=1&q=';

        fetch(giphyApi + this.props.name)
            .then(response => response.json())
            .then(response => {
                if (response.data.length > 0) {
                    this.setState({giphyUrl: response.data[0].images.original.url})
                } else {
                    // dancing cat for no images found
                    this.setState({giphyUrl: '//media.giphy.com/media/YaOxRsmrv9IeA/giphy.gif'});
                }
            });
    }

    render() {
        const {giphyUrl, isLoading} = this.state;

        if (isLoading) {
            return (<p>Loading image...</p>)
        }

        return (
            <img src={giphyUrl} alt={this.props.name} width="200"/>
        )
    }
}

export default GiphyImage